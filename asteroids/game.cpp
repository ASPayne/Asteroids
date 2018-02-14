/*********************************************************************
 * File: game.cpp
 * Description: Contains the implementaiton of the game class
 *  methods.
 *********************************************************************/
#include "game.h"
#include <cassert>

// These are needed for the getClosestDistance function...
#include <limits>
#include <algorithm>

using namespace std;

//define the static variables
bool Rock :: AndroidRocks = false;
bool Ship :: StarWars = false;

/***************************************
 * GAME CONSTRUCTOR
 ***************************************/
Game :: Game(Point tl, Point br)
 : topLeft(tl), bottomRight(br)
{
   //declare initial game values
   score = 0;
   runGame = false; //don't run the game yet! we are in the start menu
   isPaused= false; //the game is not paused
   assert (STARTING_NUMBER_OF_ROCKS >= 1); // make sure the user did not modify asteroidVariables.h incorrecly

   //delcare objects
   ship = Ship(); //our ship
   startMenu = StartMenu(); //the start menu at the begining of the game

   //create a list of Rocks (asteroids)
   rHead = new Rock();
   rEnd = rHead;
   rHead->playWithAndroid(false);//we are not initially drawing androids on the screen
   for (int i = 0; i < STARTING_NUMBER_OF_ROCKS; i++)
   {
      Rock * theRock = new BigRock();

      //make sure it is a good distance away from the ship when it spawns
      while (getClosestDistance(ship, *theRock) < ((ship.getCollisionRadius()*1.5) + theRock->getCollisionRadius()))
      {
         theRock = new BigRock();
      }

      rEnd->setNext(theRock);
      rEnd = rEnd->getNext();
   }

   //create an array of stars to be in the background
   for (int i = 0; i < NUMBER_OF_STARS; i++)
   {
      stars[i] = Star();
   }

}

/****************************************
 * GAME DESTRUCTOR
 ****************************************/
Game :: ~Game()
{
   // Look for and delete bullets
   vector<Bullet>::iterator bulletIt = bullets.begin();
   while (bulletIt != bullets.end())
   {
      Bullet bullet = *bulletIt;
      bulletIt = bullets.erase(bulletIt);
   }
   cout << "deleted all bullets\n";

   while (rHead->getNext() != NULL)
   {
      Rock * temprock = rHead;
      rHead = rHead->getNext();
      delete temprock;
   }
   delete rHead;
   cout << "deleted all asteroids\n";
}

/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game :: advance()
{
   if (runGame)//are we running the game or are we in the start menu?
   {
      if (!isPaused)// is the game paused?
      {
         advanceRocks();
         advanceShip();
         advanceBullets();
         handleCollisions();
         cleanUpZombies();
      }
   }
}

/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game :: draw(const Interface & ui)
{
   //always draw the stars first so they will be in the background
   for (int i = 0; i < NUMBER_OF_STARS; i++)
   {
      stars[i].draw();
   }

   if (runGame)//are we running the game or are we in the start menu?
   {
      if (!isPaused)//is the game paused?
      {
         // draw the asteroids
         for (Rock* currentRock = rHead->getNext(); currentRock; currentRock = currentRock->getNext())
         {
            if (currentRock->isAlive())
            {
               currentRock->draw();
            }
         }

         if (ship.isAlive())//is our ship dead?
            ship.draw();

         //draw the bullets
         for (int i = 0; i < bullets.size(); i++)
         {
            if (bullets[i].isAlive())
            {
               if (ship.isStarWars())//if the ship is in Starwars mode
                  bullets[i].drawLaser();
               else
                  bullets[i].draw();
            }
         }
      }
      else
         drawText(Point(-54, 0), "-- PAUSED --");//if the game is paused

      // Put the score on the screen
      Point scoreLocation;
      scoreLocation.setX(topLeft.getX() + 5 * OBJECT_SIZE);
      scoreLocation.setY(topLeft.getY() - 5 * OBJECT_SIZE);

      drawNumber(scoreLocation, score);
   }
   else //draw the start menu screen
   {
      startMenu.draw();
   }
}

/***************************************
 * GAME :: HANDLE INPUT
 * accept input from the user
 ***************************************/
void Game :: handleInput(const Interface & ui)
{
   if (runGame)//are we running the game or are we in the start menu?
   {
      if (!isPaused)//is the game paused?
      {
         if (ui.isLeft())
         {
            ship.turnLeft();
         }

         if (ui.isRight())
         {
            ship.turnRight();
         }

         if (ui.isUp())
         {
            ship.setThrust(ui.isUp());
         }

         if (!ui.isUp())
         {
            ship.setThrust(ui.isUp());
         }

         if (ui.isSpace())
         {
            if (ship.isAlive())
            {
               Bullet newBullet;
               if (ship.isStarWars())
               {
                  newBullet.fire(ship.getFiringLocation(), Point(0,0), ship.getRotation());
               }
               else
               {
                  newBullet.fire(ship.getFiringLocation(), ship.getVelocityPoint(), ship.getRotation());
               }
               bullets.push_back(newBullet);
            }
         }
         //test for additional buttons
         if (ui.isA())
         {
            //turn on/off android mode
            if (!rHead->getPlayWithAndroid())
               cout << "hey! we finally found the droid we were looking for!\n";
            rHead->playWithAndroid(!rHead->getPlayWithAndroid());
         }
         if (ui.isS())
         {
            //turn on/off starwars mode
            if (!ship.isStarWars())
               cout << "Congrats! You joined the dark side!\n";
            ship.playStarWars(!ship.isStarWars());
         }
      }//isPaused

      if (ui.isEsc())
      {
         isPaused = (!isPaused); //pause or unpause
         if (isPaused)
         {
            cout << "you paused the game\n";
         }
         else
         {
            cout << "you unpaused the game\n";
         }
      }
   }
   else //if we are in the start menu
   {
      if (ui.isSpace())
      {
         runGame = true;//run the game
      }
   }
}

/***************************************
 * GAME :: ADVANCE ROCKS
 * Go through each rock (asteroid) and advance it.
 ***************************************/
void Game :: advanceRocks()
{
   for (Rock * currentRock = rHead->getNext(); currentRock; currentRock = currentRock->getNext())
   {
      if (currentRock->isAlive())
      {
         currentRock->advance();
      }
   }
}

/***************************************
 * GAME :: ADVANCE SHIP
 * advance the ship
 ***************************************/
void Game :: advanceShip()
{
   if (ship.isAlive())
      ship.advance();
   else
   {
   drawText(Point(-40,0), "you died!");
   drawText(Point(-40,-40), "Final Score: ");
   drawNumber(Point(0,-50 * OBJECT_SIZE), score);
   }
}

/***************************************
 * GAME :: ADVANCE BULLETS
 * Go through each bullet and advance it.
 ***************************************/
void Game :: advanceBullets()
{
   // Move each of the bullets forward if it is alive
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i].isAlive())
      {
         // this bullet is alive, so tell it to move forward
         bullets[i].advance();

         if (bullets[i].getHealth() <= 0)
         {
            bullets[i].kill();
         }
      }
   }
}

/**************************************************************************
 * GAME :: HANDLE COLLISIONS
 * Check for a collision between a asteroid and a bullet.
 * Also checks for cloision between the ship and asteroids.
 **************************************************************************/
void Game :: handleCollisions()
{
   for (Rock* currentRock = rHead->getNext(); currentRock; currentRock = currentRock->getNext())
   {
      if (currentRock->isAlive())
      {
      //check for rock and ship collision
         if (ship.isAlive())
         {
            if (getClosestDistance(ship, *currentRock) < (ship.getCollisionRadius() + currentRock->getCollisionRadius()))
            {
               cout << "you're dead!\n";
               ship.kill();
               currentRock->kill();
            }
         }
      //check for rock and bullet collision
         for (int b = 0; b < bullets.size(); b++)
         {
            if (bullets[b].isAlive())
            {
               if (getClosestDistance(bullets[b], *currentRock) <= (bullets[b].getCollisionRadius() + currentRock->getCollisionRadius()))
               {
                  score += currentRock->getScoreAmount();
                  currentRock->kill();
                  currentRock->setAngle(bullets[b].getAngle());
                  bullets[b].kill();
               }
            }
         }
      }
   }
}


/**************************************************************************
 * GAME :: CLEAN UP ZOMBIES
 * Remove any dead objects (take bullets and rocks out of their lists)
 **************************************************************************/
void Game :: cleanUpZombies()
{
   // Look for dead asteroids
   for (Rock* currentRock = rHead; currentRock; currentRock = currentRock->getNext())
   {
      if (currentRock->getNext() != NULL)
      {
         if (!currentRock->getNext()->isAlive())
         {
            Rock * deadRock;
            deadRock = currentRock->getNext();
            //cout << "KABOOM!\n";
            deadRock->multiply(currentRock);
            delete deadRock;
         }
      }
   }

   // Look for dead bullets
   vector<Bullet>::iterator bulletIt = bullets.begin();
   while (bulletIt != bullets.end())
   {
      Bullet bullet = *bulletIt;

      if (!bullet.isAlive())
      {
         // remove from list and advance
         bulletIt = bullets.erase(bulletIt);
      }
      else
      {
         bulletIt++; // advance
      }
   }
}

/**********************************************************
 * Function: getClosestDistance
 * Description: Determine how close these two objects will
 *   get in between the frames.
 **********************************************************/

float Game :: getClosestDistance(const Projectile &obj1, const Projectile &obj2) const
{
   // find the maximum distance traveled
   float dMax = max(abs(obj1.getVelocityX()), abs(obj1.getVelocityY()));
   dMax = max(dMax, abs(obj2.getVelocityX()));
   dMax = max(dMax, abs(obj2.getVelocityY()));
   dMax = max(dMax, 0.1f); // when dx and dy are 0.0. Go through the loop once.

   float distMin = std::numeric_limits<float>::max();
   for (float i = 0.0; i <= dMax; i++)
   {
      Point point1(obj1.getLocation().getX() + (obj1.getVelocityX() * i / dMax),
                     obj1.getLocation().getY() + (obj1.getVelocityY() * i / dMax));
      Point point2(obj2.getLocation().getX() + (obj2.getVelocityX() * i / dMax),
                     obj2.getLocation().getY() + (obj2.getVelocityY() * i / dMax));

      float xDiff = point1.getX() - point2.getX();
      float yDiff = point1.getY() - point2.getY();

      float distSquared = (xDiff * xDiff) + (yDiff * yDiff);

      distMin = min(distMin, distSquared);
   }

   return sqrt(distMin);
}
