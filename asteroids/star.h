/***********************************************************************
 * Source File:
 *    Star : an object in the background
 * Author:
 *    Andrew Payne
 * Summary:
 *    draw a dot on the screen to represent a star in the background
 ************************************************************************/
#ifndef STAR_H
#define STAR_H

#include "asteroidVariables.h"
#include "point.h"
#include "uiDraw.h"

class Star
{
   public:
      Star();
      ~Star(){};
      void draw();

   private:
      Point location;
      double baseColor;
      double red;
      double blue;
      double green;
};

#endif /* STAR_H */
