# BreakoutGame

This is a Breakout style game where the paddle is controlled by the mouse. Click the mouse to release the ball from the paddle and start the game. 

After breaking all the bricks, the board is reset and the speed of the ball is increased with each level. Each player has three lives.

**Configuration instructions for Windows Visual Studio are after the screenshots.**

<img src="https://github.com/Ambrose-M/BreakoutGame/blob/master/game2D/Images/forReadMe/OpeningScreen.PNG" alt="oScreen"
	title="Opening Screen" width="400" height="400" />     <img src="https://github.com/Ambrose-M/BreakoutGame/blob/master/game2D/Images/forReadMe/Level1.png" alt="Level1"
	title="Level 1" width="400" height="400" />     <img src="https://github.com/Ambrose-M/BreakoutGame/blob/master/game2D/Images/forReadMe/GameOverScreen.PNG" alt="GameOver"
	title="Game Over Screen" width="400" height="400" />

This game uses three Simple DirectMedia Layer development libraries: SDL2, SDL_image, and SDL_ttf. Download their zips under the Development Libraries title in these links:

* https://www.libsdl.org/download-2.0.php
* https://www.libsdl.org/projects/SDL_image/
* https://www.libsdl.org/projects/SDL_ttf/

Extract all from these zips and rename their first folder from "SDL2-devel-2.0.12-VC" to simply SDL2, SDL2_image, and SDL2_ttf respectively. In this project they are by default linked to VS through the path "C:\Development\...", where each library is contained in a seperate folder. Create a new folder in the C drive named Development and place the library folders inside. While in VS, you can view these file paths by right clicking the game2D project and selecting Properties -> C/C++ -> General -> Additional Include Directories. 

If there are issues setting up or connecting to the SDL libraries, follow the tutorial below to start fresh after uploading Breakout to Visual Studio. Repeat this process for the SDL_image and SDL_tff libraries. Setting up SDL2 alone does not automatically include them.

https://www.youtube.com/watch?v=Sfn7yOiwJLw&list=LL7ZRWZ_-kR0nmcBUI1ULz2w&index=10&t=338s
