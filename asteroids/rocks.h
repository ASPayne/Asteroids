#ifndef ROCKS_H
#define ROCKS_H


#include "asteroidVariables.h"

#include "projectile.h"
#include "point.h"
#include "uiDraw.h"
#include "velocity.h"
#include "iostream"
using namespace std;

class Rock : public Projectile
{
   private:
      int getRockType() const {return rockType;};
      static bool AndroidRocks;
      int scoreAmount;

   protected:
      void setUpVelocity(int speed);
      void setUpVelocity();
      Rock * rNext;
      int rockType; //0 = dead; 1 = small; 2 = Med; 3 = Large

   public:
      Rock();
      Rock(Point loc); /*loc is short for location*/
      virtual ~Rock();

      virtual void draw();

      void advance();

      void multiply(Rock* previousPointer);

      void playWithAndroid(bool playersChoice) {AndroidRocks = playersChoice;};
      bool getPlayWithAndroid()           const {return AndroidRocks; };

      void setNext(Rock* newNext)               {rNext = newNext;     };
      Rock* getNext()                     const {return rNext;        };

      void setScoreAmount(int amount)           {scoreAmount = amount;};
      int getScoreAmount()                const {return scoreAmount;  };
};

/***************************************
 * BIG ASTEROID
 ***************************************/
class BigRock : public Rock
{
   private:

   public:
      BigRock();
      BigRock(Point loc); //loc is short for location
      ~BigRock();
      void draw();
};

/***************************************
 * MEDIUM ASTEROID
 ***************************************/
class MedRock : public Rock
{
   private:

   public:
      MedRock();
      MedRock(Point loc); //loc is short for location
      ~MedRock();
      void draw();
};
/***************************************
 * SMALL ASTEROID
 ***************************************/
class SmallRock : public Rock
{
   private:

   public:
      SmallRock();
      SmallRock(Point loc); //loc is short for location
      ~SmallRock();
      void draw();
};

/***************************************
 * ANDROID
 ***************************************/
class Android : public Rock
{
   private:

   public:
      Android();
      Android(Point loc); //loc is short for location
      ~Android();
      void draw();
};

#endif /* rocks_h */
