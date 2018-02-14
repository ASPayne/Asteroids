/*********************************************************************
 * File: game.h
 * Description: Defines the game class for Asteroids
 *
 *********************************************************************/
#ifndef GAME_H
#define GAME_H

#include <vector>

#include "asteroidVariables.h"
#include "ship.h"
#include "rocks.h"
#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "projectile.h"
#include "bullet.h"
#include "startmenu.h"
#include "star.h"

using namespace std;

class Game
{
   public:
   /*********************************************
    * Constructor
    * Initializes the game
    *********************************************/
   Game(Point tl, Point br);
   ~Game();

   /*********************************************
    * Function: advance
    * Description: Move everything forward one
    *  step in time.
    *********************************************/
   void advance();

   /*********************************************
    * Function: draw
    * Description: draws everything for the game.
    *********************************************/
   void draw(const Interface & ui);

   /*********************************************
    * Function: handleInput
    * Description: Takes actions according to whatever
    * keys the user has pressed.
    *********************************************/
   void handleInput(const Interface & ui);

   /*********************************************
    * Function: getClosestDistance
    * Description: determines the distance between
    * two objects
    *********************************************/
   float getClosestDistance(const Projectile &obj1, const Projectile &obj2) const;

   private:
      // The coordinates of the screen
      Point topLeft;
      Point bottomRight;

      bool runGame;
      bool isPaused;

      int score;

      Rock* rHead;
      Rock* rEnd;
      vector<Rock*> Rocks;
      vector<Bullet> bullets;
      Star stars[NUMBER_OF_STARS];
      Ship ship;

      StartMenu startMenu;

      void advanceRocks();
      void advanceShip();
      void advanceBullets();
      void cleanUpZombies();
      void handleCollisions();

};
#endif /* GAME_H */
