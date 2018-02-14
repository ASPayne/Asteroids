/***********************************************************************
 * Source File:
 *    Start Menu : the the welcome screen
 * Author:
 *    Andrew Payne
 * Summary:
 *    welcomes the player to the game
 ************************************************************************/
#ifndef STARTMENU_H
#define STARTMENU_H

#include "asteroidVariables.h"
#include "uiDraw.h"
#include "point.h"

class StartMenu
{
   public:
      StartMenu();
      void draw();
   private:
      Point textLoc;
};
#endif /* STARTMENU_H */
