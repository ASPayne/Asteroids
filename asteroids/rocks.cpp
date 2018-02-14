#include "asteroidVariables.h"

#include "rocks.h"
#include "point.h"
#include "projectile.h"
#include "velocity.h"
#include "uiDraw.h"

/***************************************
 * CUSTOM START LOCATION CONSTRUCTOR
 ***************************************/
Rock :: Rock(Point loc)
{
   Projectile::setLocation(loc);
   setUpVelocity(5);
   setRotationSpeed(D_A_ROTATION_SPEED);
   setRotation(random(0, 359));
   setAlive(true);
   setScoreAmount(D_A_DESTROYED_POINTS);
   rockType = 0;
};
/***************************************
 * CONSTRUCTOR
 ***************************************/
Rock :: Rock()
{
   setLocation(Point((float)random(-(WINDOW_X_SIZE/2), WINDOW_X_SIZE/2),
                     (float)random(-(WINDOW_Y_SIZE/2), WINDOW_Y_SIZE/2)));
   setUpVelocity(5);
   setRotationSpeed(D_A_ROTATION_SPEED);
   setRotation(random(0, 359));
   setAlive(true);
   setScoreAmount(D_A_DESTROYED_POINTS);
   rockType = 0;
};

/***************************************
 * DESTRUCTOR
 ***************************************/
Rock :: ~Rock()
{
//cout << "deleted Rock\n";
};

/******************************************************************
 * Rock :: SET UP VELOCITY
 * Created to reduce amount of code that is visualy seen
 * in the constructor
 * 1. Sets a random angle
 * 2. Determines the velocity at which that rock will travel
 *    using the provided speed
 * 3. Sets a random amount the rock is rotated at
 * usually this is implemented when a rock is destroyed, creating
 * multiple other rocks
 *****************************************************************/
void Rock :: setUpVelocity(int speed)
{
   setAngle(random(0.0, 360.0));
   setSpeed(speed);
   setVelocity(getSpeed() * (cos(M_PI / 180.0 * getAngle())), //Dx
               getSpeed() * (sin(M_PI / 180.0 * getAngle()))); //Dy
   setRotation(random(0.0, 359.9));
};

/******************************************************************
 * Rock :: SET UP VELOCITY
 * Created to reduce amount of code that is visualy seen
 * in the constructor
 * 1. Sets a random angle
 * 2. Determines the velocity at which that rock will travel
 * 3. Sets a random amount the rock is rotated at
 *****************************************************************/
void Rock :: setUpVelocity()
{
   setVelocity(getSpeed() * (cos(M_PI / 180.0 * getAngle())), //Dx
               getSpeed() * (sin(M_PI / 180.0 * getAngle()))); //Dy
   setRotation(random(0.0, 359.9));
};

/******************************************************************
 * Rock :: ADVANCE
 * calls the projectile advance and increases the rotation
 *****************************************************************/
void Rock :: advance()
{
   Projectile::advance();
   setRotation(getRotation() + getRotationSpeed());
};

/******************************************************************
 * Rock :: DRAW
 * this is a virtual function
 ******************************************************************/
void Rock :: draw()
{
};

/******************************************************************
 * Rock :: MULTIPLY
 * this function is the "break-apart" function
 * this function creates and adds new rocks to the list of rocks
 * according to what type of rock is splitting up
 *****************************************************************/
void Rock::multiply(Rock* previousPointer)
{
   Rock * r1;
   Rock * r2;
   Rock * r3;

   switch(rockType)
   {
      case 4://used if I decide to make Android a fourth type of rock
      case 3://Large Rock
         r1 = new MedRock(getLocation());//create a Medium Rock
         r1->setAngle(getAngle());
         r1->setUpVelocity();
         r1->setVelocity(r1->getVelocity() + getVelocity());

         r2 = new MedRock(getLocation());//create a Medium Rock
         r2->setAngle(getAngle()+180);
         r2->setUpVelocity();
         r2->getVelocity() += getVelocity();

         r3 = new SmallRock(getLocation());//create a Small Rock
         r3->setAngle(getAngle()+90);
         r3->setUpVelocity();
         r3->getVelocity() += getVelocity();

         //add them to the list
         r1->setNext(r2);
         r2->setNext(r3);
         r3->setNext(getNext());
         previousPointer->setNext(r1);
         break;
      case 2://Medium Rock
         r1 = new SmallRock(getLocation());//create a Small Rock
         r1->setAngle(getAngle()+45);
         r1->setUpVelocity();

         r2 = new SmallRock(getLocation());//create a Small Rock
         r2->setAngle(getAngle()+135);
         r2->setUpVelocity();

         //add them to the list
         r1->setNext(r2);
         r2->setNext(getNext());
         previousPointer->setNext(r1);
         break;
      case 1://Small Rock
         previousPointer->setNext(getNext());
         break;
   }
}



/****************************\
| Large Asteroid             |
\****************************/

/**********************************************
 * BIGROCK :: CUSTOM START LOCATION CONSTRUCTOR
 **********************************************/
BigRock :: BigRock(Point loc)
{
   setLocation(loc);
   setUpVelocity(L_A_SPEED);

   if (random(-2,2) < 0) //if the number is -2 or -1
      setRotationSpeed(L_A_ROTATION_SPEED * (-1));
   else //if the number is 0 or 1
      setRotationSpeed(L_A_ROTATION_SPEED);

   setRotation (random(0, 360));
   setCollisionRadius(L_A_COLLISION_CIRCLE_RADIUS * OBJECT_SIZE);
   setAlive(true);
   setScoreAmount(L_A_DESTROYED_POINTS);
   rockType = 3;
};

/**********************************************
 * BIGROCK :: CONSTRUCTOR
 **********************************************/
BigRock :: BigRock()
{
   setLocation(Point((float)random((WINDOW_X_SIZE/(-2)), (WINDOW_X_SIZE/2)),
                     (float)random((WINDOW_Y_SIZE/(-2)), (WINDOW_Y_SIZE/2))));
   setUpVelocity(L_A_SPEED);

   if (random(-2,2) < 0) //if the number is -2 or -1
      setRotationSpeed(L_A_ROTATION_SPEED * (-1));
   else //if the number is 0 or 1
      setRotationSpeed(L_A_ROTATION_SPEED);

   setRotation(random(0.0, 360.0));
   setCollisionRadius(L_A_COLLISION_CIRCLE_RADIUS * OBJECT_SIZE);
   setAlive(true);
   setScoreAmount(L_A_DESTROYED_POINTS);
   rockType = 3;
};

/**********************************************
 * BIGROCK :: DESTRUCTOR
 **********************************************/
BigRock :: ~BigRock()
{
   //cout << "deleted large Rock\n";
};

/**********************************************
 * BIGROCK :: DRAW
 **********************************************/
void BigRock :: draw()
{
   if (!getPlayWithAndroid())
   {
      drawLargeAsteroid(getLocation(), getRotation());
   }
   else //play with android (android mode is turned on)
   {
      drawAndroid(getLocation(), getRotation(), 1);
   }
};



/****************************\
| Medium Asteroids           |
\****************************/

/**********************************************
 * BIGROCK :: CUSTOM START LOCATION CONSTRUCTOR
 **********************************************/
MedRock :: MedRock(Point loc)
{
   setLocation(loc);
   setUpVelocity(M_A_SPEED);

   if (random(-2,2) < 0) //if the number is -2 or -1
      setRotationSpeed(M_A_ROTATION_SPEED * (-1));
   else //if the number is 0 or 1
      setRotationSpeed(M_A_ROTATION_SPEED);

   setRotation (random(0, 360));
   setCollisionRadius(M_A_COLLISION_CIRCLE_RADIUS * OBJECT_SIZE);
   setAlive(true);
   setScoreAmount(M_A_DESTROYED_POINTS);
   rockType = 2;
};

/**********************************************
 * MEDIUMROCK :: CONSTRUCTOR
 **********************************************/
MedRock :: MedRock()
{
   setLocation(Point((float)random((WINDOW_X_SIZE/(-2)), (WINDOW_X_SIZE/2)),
                     (float)random((WINDOW_Y_SIZE/(-2)), (WINDOW_Y_SIZE/2))));
   setUpVelocity(M_A_SPEED);

   if (random(-2,2) < 0) //if the number is -2 or -1
      setRotationSpeed(M_A_ROTATION_SPEED * (-1));
   else //if the number is 0 or 1
      setRotationSpeed(M_A_ROTATION_SPEED);

   setRotation(random(0.0, 360.0));
   setCollisionRadius(M_A_COLLISION_CIRCLE_RADIUS * OBJECT_SIZE);
   setAlive(true);
   setScoreAmount(M_A_DESTROYED_POINTS);
   rockType = 2;
};

/**********************************************
 * MEDIUMROCK :: DESTRUCTOR
 **********************************************/
MedRock :: ~MedRock()
{
   //cout << "deleted medium Rock\n";
};

/**********************************************
 * MEDIUMROCK :: DRAW
 **********************************************/
void MedRock :: draw()
{
   if (!getPlayWithAndroid())
   {
      drawMediumAsteroid(getLocation(), getRotation());
   }
   else //play with android
   {
      drawAndroid(getLocation(), getRotation(), 2);
   }
};




/****************************\
| Small Asteroids            |
\****************************/

/************************************************
 * SMALLROCK :: CUSTOM START LOCATION CONSTRUCTOR
 ************************************************/
SmallRock :: SmallRock(Point loc)
{
   setLocation(loc);
   setUpVelocity(S_A_SPEED);

   if (random(-2,2) < 0) //if the number is -2 or -1
      setRotationSpeed(S_A_ROTATION_SPEED * (-1));
   else //if the number is 0 or 1
      setRotationSpeed(S_A_ROTATION_SPEED);

   setRotation (random(0, 360));
   setCollisionRadius(S_A_COLLISION_CIRCLE_RADIUS * OBJECT_SIZE);
   setAlive(true);
   setScoreAmount(S_A_DESTROYED_POINTS);
   rockType = 1;
};

/************************************************
 * SMALLROCK :: CONSTRUCTOR
 ************************************************/
SmallRock :: SmallRock()
{
   setLocation(Point((float)random((WINDOW_X_SIZE/(-2)), (WINDOW_X_SIZE/2)),
                     (float)random((WINDOW_Y_SIZE/(-2)), (WINDOW_Y_SIZE/2))));
   setUpVelocity(S_A_SPEED);

   if (random(-2,2) < 0) //if the number is -2 or -1
      setRotationSpeed(S_A_ROTATION_SPEED * (-1));
   else //if the number is 0 or 1
      setRotationSpeed(S_A_ROTATION_SPEED);

   setRotation(random(0.0, 360.0));
   setCollisionRadius(S_A_COLLISION_CIRCLE_RADIUS * OBJECT_SIZE);
   setAlive(true);
   setScoreAmount(S_A_DESTROYED_POINTS);
   rockType = 1;
};

/************************************************
 * SMALLROCK :: DESTRUCTOR
 ************************************************/
SmallRock :: ~SmallRock()
{
   //cout << "deleted small Rock\n";
};

/**********************************************
 * SMALLROCK :: DRAW
 **********************************************/
void SmallRock :: draw()
{
   if (!getPlayWithAndroid())
   {
      drawSmallAsteroid(getLocation(), getRotation());
   }
   else //play with android
   {
      drawAndroid(getLocation(), getRotation(), 4);
   }
};



/****************************\
| Android Asteroids            |
\****************************/

 /************************************************
 * ANDROID :: CUSTOM START LOCATION CONSTRUCTOR
 ************************************************/
Android :: Android(Point loc)
{
   setLocation(loc);
   setUpVelocity(S_A_SPEED);

   if (random(-2,2) < 0) //if the number is -2 or -1
      setRotationSpeed(L_A_ROTATION_SPEED * (-1));
   else //if the number is 0 or 1
      setRotationSpeed(L_A_ROTATION_SPEED);

   setRotation (random(0, 360));
   setCollisionRadius(L_A_COLLISION_CIRCLE_RADIUS * OBJECT_SIZE);
   setAlive(true);
   setScoreAmount(L_A_DESTROYED_POINTS);
   rockType = 4;
};

/************************************************
 * ANDROID :: CONSTRUCTOR
 ************************************************/
Android :: Android()
{
   setLocation(Point((float)random((WINDOW_X_SIZE/(-2)), (WINDOW_X_SIZE/2)),
                     (float)random((WINDOW_Y_SIZE/(-2)), (WINDOW_Y_SIZE/2))));
   setUpVelocity(S_A_SPEED);

   if (random(-2,2) < 0) //if the number is -2 or -1
      setRotationSpeed(L_A_ROTATION_SPEED * (-1));
   else //if the number is 0 or 1
      setRotationSpeed(L_A_ROTATION_SPEED);

   setRotation(random(0.0, 360.0));
   setCollisionRadius(L_A_COLLISION_CIRCLE_RADIUS * OBJECT_SIZE);
   setAlive(true);
   setScoreAmount(L_A_DESTROYED_POINTS);
   rockType = 4;
};

/************************************************
 * ANDROID :: DESTRUCTOR
 ************************************************/
Android :: ~Android()
{
   //cout << "deleted android Rock\n";
};

/************************************************
 * ANDROID :: DRAW
 ************************************************/
void Android :: draw()
{
      drawAndroid(getLocation(), getRotation(), 0);
};

