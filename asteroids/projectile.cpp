/***********************************************************************
 * Source File:
 *    Projectile : a an inherited object that gives flying objects
 *    a point, a velocity and life (alive or dead)
 * Author:
 *    Andrew Payne
 * Summary:
 *    Projectile's larger functions, all other functions are in the .h file
 ************************************************************************/
#include "asteroidVariables.h"
#include "projectile.h"
#include "point.h"

/******************************************************************
 * PROJECTILE :: ADVANCE
 * moves the flying object
 ******************************************************************/
void Projectile :: advance()
{
   location.setX(location.getX() + getVelocityX());
   location.setY(location.getY() + getVelocityY());


   //screen wrap projectiles
   if (location.getX() < (-(WINDOW_X_SIZE /2)))
      location.setX(location.getX() + WINDOW_X_SIZE);
   else if (location.getX() > (WINDOW_X_SIZE / 2))
      location.setX(location.getX() - WINDOW_X_SIZE);

   if (location.getY() < (-(WINDOW_Y_SIZE /2)))
      location.setY(location.getY() + WINDOW_Y_SIZE);
   else if (location.getY() > (WINDOW_Y_SIZE / 2))
      location.setY(location.getY() - WINDOW_Y_SIZE);

   //allows the rotation angle to reset that it will not overload a float
   if (getRotation() > 360)
      setRotation(getRotation() - 360);
   if (getRotation() < 0)
      setRotation(getRotation() + 360);
};
