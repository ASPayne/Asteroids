/*********************************************************
 * this header file is used for global variables that are really not
 * global variables. however, every class will have the opportunity
 * use these variables as I have planned to use this file.
 * by keeping all these variables in one place, I can modify the
 * game to have different values by only changing one file.
 *********************************************************/
#ifndef ASTEROIDVARIABLES_H
#define ASTEROIDVARIABLES_H

#define WINDOW_X_SIZE 800 //default = 400 //favorite size = 1450
#define WINDOW_Y_SIZE 800 //default = 400 //favorite size = 800
#define OBJECT_SIZE 2 //default = 1 //favorite size = 2
#define STARTING_NUMBER_OF_ROCKS 5 //default = 5
#define NUMBER_OF_STARS 50

//Bullet Constants
#define BULLET_SPEED 10 //default = 5 (5 * Objectsize)
#define BULLET_HEALTH 40  //default = 40
#define BULLET_COLLISION_CIRCLE_RADIUS 1

//Ship Constants
#define SHIP_ACCELERATION_RATE 0.5 //default = 0.5 //favorite speed = 0.25 * ObjectSize
#define SHIP_ROTATION_SPEED 6
#define SHIP_COLLISION_CIRCLE_RADIUS 10

//default variables for the asteroids
//Large Asteroid
#define L_A_SPEED 1 //pixels per frame (default = 1)
#define L_A_ROTATION_SPEED 2 //degrees per frame (default = 2)
#define L_A_COLLISION_CIRCLE_RADIUS 16 //default = 16
#define L_A_DESTROYED_POINTS 5

//Medium Asteroid
#define M_A_SPEED 1.75 //pixels per frame
#define M_A_ROTATION_SPEED 5 //degrees per frame
#define M_A_COLLISION_CIRCLE_RADIUS 8
#define M_A_DESTROYED_POINTS 10

//Small Asteroid
#define S_A_SPEED 2.5  //pixels per frame
#define S_A_ROTATION_SPEED 10 //degrees per frame
#define S_A_COLLISION_CIRCLE_RADIUS 4
#define S_A_DESTROYED_POINTS 20

//default Asteroid
#define D_A_SPEED 1
#define D_A_ROTATION_SPEED 1
#define D_A_COLLISION_CIRCLE_RADIUS 5
#define D_A_DESTROYED_POINTS 5

#endif
