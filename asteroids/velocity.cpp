/***********************************************************************
 * Implementation File:
 *    VELOCITY
 * Author:
 *    Andrew Payne
 * Summary:
 *    This class is used to determine the velocity of any projectile
 ************************************************************************/
#include "point.h"
#include "velocity.h"
/********************************************
 * VELOCITY :: CONSTRUCTORS
 ********************************************/
Velocity :: Velocity()
{
   inertia = Point((float)0.0, (float)0.0);
};

Velocity :: Velocity(float x, float y)
{
   inertia = Point(x,y);
};

Velocity :: Velocity(Point p)
{
   inertia = p;
};
