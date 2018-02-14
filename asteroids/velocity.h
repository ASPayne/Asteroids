/***********************************************************************
 * Header File:
 *    VELOCITY
 * Author:
 *    Andrew Payne
 * Summary:
 *    the Velocity class header
 ************************************************************************/

#ifndef VELOCITY_H
#define VELOCITY_H

#include "point.h"
#include <cmath> //used for getting the angle

class Velocity
{
   public:
      Velocity(float x, float y);
      Velocity(Point p);
      Velocity();

      float getAngle()    {return((float)tan(dy / dx));};
      float getDx() const {return inertia.getX();};
      float getDy() const {return inertia.getY();};

      void setDx(float x) {inertia.addX(x);};
      void setDy(float y) {inertia.addY(y);};

      Point getInertia() const {return inertia;};

      inline const Velocity operator + (const Velocity & v2)
      {
         Velocity v((getDx() + v2.getDx()),(getDy() + v2.getDy()));
         return v;
      };

      inline void operator += (const Velocity & v2)
      {
         setDx(getDx() + v2.getDx());
         setDy(getDy() + v2.getDy());
      };

   private:
      Point inertia;
      float dx;
      float dy;
      float angle;
   };
#endif
