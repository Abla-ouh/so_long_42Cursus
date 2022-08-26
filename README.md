<h1 align="center">LET'S PLAY A CUTE 2D GAME :) </h1>


![test](https://i.imgur.com/l1chEB6.gif)

Hi !  This project is a very small 2D game. Its purpose is to make you work with textures, sprites, and some other very basic gameplay elements.

---
#### Based on a small library made by 42 school to make the implementation of the game kinda easy for us. For more information check its documentation here [MiniLibX documentation](https://harm-smits.github.io/42docs/libs/minilibx)



--- 
## The concept is like ...
The player has to collect the "collectibles" before he can leave the map through the exit(s). The map is a file ".ber" loaded as an argument of the executable. The number of moves are counted and the goal is to join the exit with the minimum number of moves.

---
## Some rules to follows ....
-   Only  `P`  _(Player)_,   `1`  _(wall)_,  `0`  _(Floor)_,  `C`  _(collectible)_,  `E`  _(exit)_ and I added `G` for the enemy ( Bonus part ) will be accepted characters in our map.
-   The map must be rectangular, i.e. all rows must have the same length
-   There must be at least one exit, one player, and one collectible on the map
-   The map must be closed, i.e. surrounded by walls
- For the bonus part , it must have a counter on the window and also an animation.

If any of these checks fail, the game must end with a custom error message.

----

## How to compile it ? 
For **Mandatory** part : 
	 --> `make`
	 --> `./so_long <a valid map>`

For **Bonus** part : 
	  --> `make bonus`
	  --> `./so_longbonus <a valid map>`
	 
_PS : U can find some maps on Maps folder._

	  
   
#### U can find the project's subject here , for more details : [so_long subject](https://cdn.intra.42.fr/pdf/pdf/58597/en.subject.pdf)
#### PS : If you see any error to fix , please dont hesitate to repport it, and u find my project interesting star it. feel free !! `*_*`
