/***********************************************************************
 * Source File:
 *    bullet : the projetctile used to shoot ships
 * Author:
 *    Andrew Payne
 * Summary:
 *    all the information that is needed to locate and draw bullets and lasers
 ************************************************************************/
#include "bullet.h"
#include <cmath>

/******************************************************************
 * BULLET CONSTRUCTOR
 ******************************************************************/
Bullet::Bullet()
{
   setAlive(false);
   setCollisionRadius(BULLET_COLLISION_CIRCLE_RADIUS);
};

/******************************************************************
 * BULLET :: FIRE
 * gives the bullet a start location and a velocity in which to travel
 ******************************************************************/
void Bullet::fire(Point startLocation, Point startVelocity, float direction)
{
   setAlive(true);
   setHealth(BULLET_HEALTH);
   setVelocity(startVelocity.getX() + (BULLET_SPEED * (sin(M_PI / 180.0 * (-direction)))), //Dx
               startVelocity.getY() + (BULLET_SPEED * (cos(M_PI / 180.0 * (-direction))))); //Dy
   setLocation(startLocation);
   setAngle(direction);
};

/******************************************************************
 * BULLET :: DRAW
 * draw the bullet
 ******************************************************************/
void Bullet::draw()
{
   drawDot(getLocation());
};

/******************************************************************
 * BULLET :: DRAW LASER
 * draw a laser called when the ship is in StarWars mode
 ******************************************************************/
void Bullet::drawLaser()
{
   drawLine(getLocation(), Point(getLocation().getX() + (getVelocityX()*2),(getLocation().getY() + (getVelocityY() * 2))), 1.0, 0.0, 0.0);
};

/******************************************************************
 * BULLET :: ADVANCE
 * Advance the bullet
 ******************************************************************/
void Bullet::advance()
{
   Projectile :: advance();
   setHealth(getHealth() - 1);
};
