/***********************************************************************
 * Source File:
 *    Start Menu : the the welcome screen
 * Author:
 *    Andrew Payne
 * Summary:
 *    welcomes the player to the game
 ************************************************************************/
#include "startmenu.h"
#include "point.h"
#include "uiDraw.h"
/******************************************************************
 * STAR :: CONSTRUCTOR
 ******************************************************************/
StartMenu :: StartMenu()
{
textLoc = Point(-50, (WINDOW_Y_SIZE/5));
};

/******************************************************************
 * STAR :: DRAW
 * draws the screen
 ******************************************************************/
void StartMenu :: draw()
{
   drawText(textLoc, "Welcome to:");

   drawText(Point(-198, (WINDOW_Y_SIZE/5)-20),  "    _        _                 _     _      ");
   drawText(Point(-198, (WINDOW_Y_SIZE/5)-36),  "   / \\   ___| |_ ___ _ __ ___ (_) __| |___  ");
   drawText(Point(-198, (WINDOW_Y_SIZE/5)-52),  "  / _ \\ / __| __/ _ \\ '__/ _ \\| |/ _` / __| ");
   drawText(Point(-198, (WINDOW_Y_SIZE/5)-68),  " / ___ \\\\__ \\ ||  __/ | | (_) | | (_| \\__ \\ ");
   drawText(Point(-198, (WINDOW_Y_SIZE/5)-84),  "/_/   \\_\\___/\\__\\___|_|  \\___/|_|\\__,_|___/ ");

   drawText(Point(-108, (-WINDOW_Y_SIZE/4)), "--PRESS SPACE TO START--");

   drawText(Point(-157.5, (-(WINDOW_Y_SIZE/2))+30.0), "This project was brought to you by:");
   drawText(Point(-139.5, (-(WINDOW_Y_SIZE/2))+15.0), "the language C and the number F");
};


/*
    _        _                 _     _
   / \   ___| |_ ___ _ __ ___ (_) __| |___
  / _ \ / __| __/ _ \ '__/ _ \| |/ _` / __|
 / ___ \\__ \ ||  __/ | | (_) | | (_| \__ \
/_/   \_\___/\__\___|_|  \___/|_|\__,_|___/
*/
