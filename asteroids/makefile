###############################################################
# Program:
#     Project 13, Asteroids
#     Brother Ercanbrack, CS165
# Author:
#     Andrew Payne
# Summary:
#     Reproduction of the classic game ASTEROIDS
# Above and Beyond
#     0. I included a README file. you should read it.
#     1. by modifying the and recompiling asteroidVariables.h the user can
#         a. customize the screen size
#         b. modify the size of the objects drawn on the screen
#         c. change the number of rocks drawn at the start of the game
#         d. change the number of stars drawn in the background
#         e. modify the default speed and health(how many frames it will be alive for)
#               as well as the collision size for the bullets
#         f. modify the speed, rotaion speed, collision rasdius and how many points
#               are recived for destroying each tyoe of Asteroid
#     2. start menu (a welcome screen)
#     3. stars are drawn in the background
#     4. pressing ESC pauses the game
#     5. the asteroids can rotate either direction
#     6. when the ship crashes, a message displays stating that you died and providing your score
#     7. by pressing 'a' the user can change the appearance of the asteroids (and a message
#           also displays in the command window)
#     9. by pressing 's' the user can change the appearance of the ship and bullets (and a
#           message is displayed in the cammand window)
#    10. when a large asteroid breaks up, the small asteroid goes in the direction
#           the bullet was traveling
#    11. you are likely too busy to recognize that I skipped number 8 in this list
###############################################################

LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main game
###############################################################
a.out: driver.o game.o uiInteract.o uiDraw.o point.o velocity.o projectile.o ship.o bullet.o rocks.o startmenu.o star.o
	g++ driver.o game.o uiInteract.o uiDraw.o point.o velocity.o projectile.o ship.o bullet.o rocks.o startmenu.o star.o $(LFLAGS)

###############################################################
# Individual files
#    uiDraw.o       Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o   Handles input events
#    point.o        The position on the screen
#    game.o         Handles the game interaction
#    velocity.o     Velocity (speed and direction)
#    projectile.o   Base class for all flying objects
#    ship.o         The player's ship
#    bullet.o       The bullets fired from the ship
#    rocks.o        Contains all of the Rock classes
#    startmenu.o    contains code to draw the start menu
#    star.o         An object to represent stars
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h asteroidVariables.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h asteroidVariables.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

driver.o: driver.cpp game.h asteroidVariables.h
	g++ -c driver.cpp

game.o: game.cpp game.h uiDraw.h uiInteract.h point.h velocity.h projectile.h bullet.h rocks.h ship.h asteroidVariables.h startmenu.h star.h
	g++ -c game.cpp

velocity.o: velocity.cpp velocity.h point.h asteroidVariables.h
	g++ -c velocity.cpp

projectile.o: projectile.cpp projectile.h point.h velocity.h uiDraw.h asteroidVariables.h
	g++ -c projectile.cpp

ship.o: ship.cpp ship.h projectile.h point.h velocity.h uiDraw.h asteroidVariables.h
	g++ -c ship.cpp

bullet.o: bullet.cpp bullet.h projectile.h point.h velocity.h uiDraw.h asteroidVariables.h
	g++ -c bullet.cpp

rocks.o: rocks.cpp rocks.h projectile.h point.h velocity.h uiDraw.h asteroidVariables.h
	g++ -c rocks.cpp

startmenu.o: startmenu.cpp startmenu.h uiDraw.h point.h asteroidVariables.h star.h
	g++ -c startmenu.cpp

star.o: star.cpp star.h point.h asteroidVariables.h uiDraw.h
	g++ -c star.cpp

asteroidVariables.o: asteroidVariables.h


###############################################################
# General rules
###############################################################
clean:
	rm *.o *.out

tar:
	tar -cf asteroids.tar makefile *.cpp *.h *.txt

submit:
	submit asteroids.tar
