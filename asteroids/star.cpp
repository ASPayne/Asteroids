/***********************************************************************
 * Source File:
 *    Star : an object in the background
 * Author:
 *    Andrew Payne
 * Summary:
 *    draw a dot on the screen to represent a star in the background
 ************************************************************************/
#include "star.h"

/******************************************************************
 * STAR :: Constructor
 ******************************************************************/
Star::Star()
{
   //put the location of the star randomly on the screen
   location = Point(random(0, WINDOW_X_SIZE) - (WINDOW_X_SIZE / 2),
                    random(0, WINDOW_Y_SIZE) - (WINDOW_Y_SIZE / 2));

   //this is how bright the star is
   baseColor = random(0.0, 1.0);

   //generate how much of each color will be added to the star
   red = (baseColor + random(-0.1, 0.2));
   green = (baseColor + random(-0.1, 0.2));
   blue = (baseColor + random(-0.1, 0.2));
}

/******************************************************************
 * STAR :: DRAW
 * draw the star
 ******************************************************************/
void Star::draw()
{
   drawStar(location, red, green, blue);
}
