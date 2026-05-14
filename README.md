# 2D Raycaster

A simple Raycaster built in C using the Raylib library

## Demo Video
<video src="https://github.com/user-attachments/assets/2713c30f-63de-4adb-a057-8a5bf3926209" controls="controls" style="max-width: 600px;">
</video>

## Info
* Boundary walls are random and their position changes each time the program is run
* WASD movement 
* Player positon can also be changed by left clicking the player and dragging the mouse
* Player movement forward or backward using the W and S keys
* Player has a 180 degree FOV, player can be rotated using A and D keys.


## Installation

### Prerequisites
* C compiler (GCC)
* Raylib library

### Installing Raylib
* If you don't have Raylib installed, follow the instructions on the [Raylib installation page](https://github.com/raysan5/raylib#installation).

### Building the Game
1. Clone the repository:
   ```sh
    git clone https://github.com/logorhythmic/2D-Raycaster.git
   ```

2. Compile the game:
   ```sh 
    gcc -O3 src/*.c -o output -lraylib -lm -lX11 
   ```

3. Run the game:
   ```sh
   ./output
   ```
> **Note:** If you have make installed you can skip the above steps and just run ```make run```.




