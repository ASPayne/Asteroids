#ifndef ship_h
#define ship_h

#include "projectile.h"
#include "uiDraw.h"

class Ship : public Projectile
{
   private:
      bool thrust;
      static bool StarWars;
      int xWingBlaster; //0 = left side, 1 = right side

   public:
      Ship();
      ~Ship();

      void draw();
      void turnRight() {setRotation(getRotation() - SHIP_ROTATION_SPEED);};
      void turnLeft()  {setRotation(getRotation() + SHIP_ROTATION_SPEED);};
      void setThrust(bool THRUST)           {thrust = THRUST;            };
      void advance();

      void setXwingBlaster()               {xWingBlaster = !xWingBlaster;};
      int getXwingBlaster()           const {return xWingBlaster;        };
      void playStarWars(bool playersChoice) {StarWars = playersChoice;   };
      bool isStarWars()               const {return StarWars;            };

      Point getFiringLocation();

      bool getThrust()                const {return thrust;              };
};

#endif /* ship_h */
