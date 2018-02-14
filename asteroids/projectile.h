/***********************************************************************
 * Header File:
 *    Projectile : a an inherited object that gives flying objects
 *    a point, a velocity, and life (alive or dead)
 * Author:
 *    Andrew Payne
 * Summary:
 *    Projectile's functions and private variables
 ************************************************************************/

#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "asteroidVariables.h"
#include "point.h"
#include "uiDraw.h"
#include "velocity.h"

class Projectile
{
   private:
      float angle; // the angle (not the vector!!) at wich the projectile is traveling
      int rotation; // the angle at which the projectile is facing
      int collisionRadius;
      int rotationSpeed;
      int speed;

      bool alive;

      Projectile * pNext;
      Velocity velocity;
      Point location;

   public:
      //constructors and destructor
      Projectile(){pNext = NULL;};
      virtual ~Projectile(){};

      //setters
      void setCollisionRadius(int r)     {collisionRadius = r;        };
      void setRotation(int rotate)       {rotation = rotate;          };
      void setLocation(Point loc)        {location = loc;             };
      void setVelocity(Point p)          {velocity = Velocity(p);     };
      void setVelocity(Velocity v)       {velocity = v;               };
      void setVelocity(float x, float y) {velocity = Velocity(x,y);   };
      void setAlive(bool a)              {alive = a;                  };
      void setAngle(float ANGLE)         {angle = ANGLE;              };
      void setSpeed(int SPEED)           {speed = SPEED;              };
      void setRotationSpeed(int rSpeed)  {rotationSpeed = rSpeed;     };
      void setNext (Projectile* newNext) {pNext = newNext;            };

      //getters
      float getVelocityX()     const {return velocity.getDx();        };
      float getVelocityY()     const {return velocity.getDy();        };
      float getLocationX()     const {return location.getX();         };
      float getLocationY()     const {return location.getY();         };
      float getAngle()         const {return angle;                   };

      int getCollisionRadius() const {return collisionRadius;         };
      int getRotation()        const {return rotation;                };
      int getSpeed()           const {return speed;                   };
      int getRotationSpeed()   const {return rotationSpeed;           };

      Point getLocation()      const {return location;                };
      Point getVelocityPoint() const {return velocity.getInertia();   };

      Velocity getVelocity()   const {return velocity;                };

      bool isAlive()           const {return alive;                   };

      Projectile* getNext()    const {return pNext;                   };

      //other functions
      void kill()                    {setAlive(false);                };
      void advance();
      virtual void draw() = 0;
   };

#endif /* projectile_h */
