## Conway's Game of Life

A Simple implementation of Conway's Game of Life in Cpp using Raylib.

### Build using CMake

```bash
git clone https://github.com/gautam8404/Conway-Game-of-Life-cpp
cd Conway-Game-of-Life-cpp

mkdir build
cd build
cmake ..
cmake --build .
```

### Build using g++

```bash
git clone https://github.com/gautam8404/Conway-Game-of-Life-cpp
cd Conway-Game-of-Life-cpp

g++ -std=c++17 -o game-of-life main.cpp -lraylib
```

### Controls

-  Left Click to toggle cell state
-  Space to Pause
-  C to Clear
-  S to Slow Down
-  F to Speed Up
-  D to Default Speed
-  R to Randomize
-  G for GliderGun