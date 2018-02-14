/***********************************************************************
 * Source File:
 *    bullet : the projetctile used to shoot ships
 * Author:
 *    Andrew Payne
 * Summary:
 *    all the information that is needed to locate and draw bullets and lasers
 ************************************************************************/
#ifndef bullet_h
#define bullet_h

#include "uiDraw.h"
#include "point.h"
#include "asteroidVariables.h"
#include "projectile.h"

class Bullet: public Projectile
{
   private:
      int health;
      bool alive;

   public:
      Bullet();
      ~Bullet(){};
      void fire(Point startLocation, Point startVelocity, float direction);
      void draw();
      void drawLaser();
      void setHealth(int HP) {health = HP;};
      void advance();

      int getHealth() const {return health;};
};
#endif /* bullet_h */
