#include "ship.h"
#include "projectile.h"
#include "uiDraw.h"

Ship :: Ship()
{
   setLocation(Point(0,0));
   setRotation(random(0,360));
   setThrust(false);
   setSpeed(SHIP_ACCELERATION_RATE);
   setCollisionRadius(SHIP_COLLISION_CIRCLE_RADIUS * OBJECT_SIZE);
   setAlive(true);
   xWingBlaster = 0; // the first blaster shot will be on the left side
};

Ship :: ~Ship()
{
};

Point Ship :: getFiringLocation()
{
   if (StarWars)
   {
         //{-12,4}
      if (xWingBlaster)
      {
         Point pt((getLocationX() + (-12 * OBJECT_SIZE) * -1), //fire on the right side of ship
                  (getLocationY() + (4 * OBJECT_SIZE)));
         rotate(pt, getLocation(), getRotation());
         setXwingBlaster();//fire next shot on other side
         return pt;
      }
      if (!xWingBlaster)
      {
         Point pt((getLocationX() + (-12 * OBJECT_SIZE)), //fire on the left side of ship
                  (getLocationY() + (4 * OBJECT_SIZE)));
         rotate(pt, getLocation(), getRotation());
         setXwingBlaster();//fire next shot on other side
         return pt;
      }
   }
   else
   {
      Point pt((getLocationX() + (0 * OBJECT_SIZE)),
               (getLocationY() + (6 * OBJECT_SIZE)));
      rotate(pt, getLocation(), getRotation());
      return pt;
   }
}

void Ship :: advance()
{
   Projectile::advance();

   //I am sure there is a more simple way of doing this... however, this will work for now
   if (getThrust())
   {
   setVelocity(getVelocityX() + (SHIP_ACCELERATION_RATE * (sin(M_PI / 180.0 * (-getRotation())))), //Dx
               getVelocityY() + (SHIP_ACCELERATION_RATE * (cos(M_PI / 180.0 * (-getRotation()))))); //Dy
   }
};


void Ship :: draw()
{
   if (StarWars)
      drawXWing(getLocation(), getRotation(), getThrust());
   else
      drawShip(getLocation(), getRotation(), getThrust());
};
