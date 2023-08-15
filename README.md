## Conway's Game of Life

A Simple implementation of Conway's Game of Life in Cpp using Raylib.

### Build using CMake

```bash
git clone https://github.com/gautam8404/Conway-Game-of-Life-cpp
cd Conway-Game-of-Life-cpp

mkdir build
cd build
cmake ..
make
```

### Build using g++

```bash
git clone https://github.com/gautam8404/Conway-Game-of-Life-cpp
cd Conway-Game-of-Life-cpp

g++ -std=c++17 -o game-of-life main.cpp -lraylib
```

### Controls

-  Press/Hold Left Mouse Button: Cell Alive
-  Press/Hold Right Mouse Button: Cell Dead
-  Space: Pause
-  T: Toggle Grid Lines
-  C: Clear
-  S: Slow Down
-  F: Speed Up
-  D: Default Speed
-  R: Randomize
-  G: GliderGun * 1. Any live cell with fewer than two live neighbours dies, as if by underpopulation
 * 2. Any live cell with two or three live neighbours lives on to the next generation
 * 3. Any live cell with more than three live neighbours dies, as if by overpopulation.
 * 4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
 *


### Rules

 1. Any live cell with fewer than two live neighbours dies, as if by underpopulation
 2. Any live cell with two or three live neighbours lives on to the next generation
 3. Any live cell with more than three live neighbours dies, as if by overpopulation.
 4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
 
