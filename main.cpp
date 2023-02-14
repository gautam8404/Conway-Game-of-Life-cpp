/*
 *
 *
 * Conway's Game if Life
 *
 * 1. Any live cell with fewer than two live neighbours dies, as if by underpopulation
 * 2. Any live cell with two or three live neighbours lives on to the next generation
 * 3. Any live cell with more than three live neighbours dies, as if by overpopulation.
 * 4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
 *
 *
 */


#include <string>
#include <iostream>
#include "raylib.h"

// Global Variables
typedef enum {
    DEAD,
    ALIVE
} Cell;

const unsigned int screenWidth = 800;
const unsigned int screenHeight = 640;
const unsigned int cellSize = 10;
const unsigned int cellCountX = screenWidth / cellSize;
const unsigned int cellCountY = screenHeight / cellSize;
const char *title = "Conway's Game of Life";

Cell grid[cellCountX][cellCountY];

double updateInterval = 0.1;
double slowestUpdateInterval = 2.0;
double fastestUpdateInterval = 0.001;
double updateIntervalStep = 0.04;
double lastUpdate = 0.0;

// controls
bool paused = true;
bool showedControlsAtStart = false;

// Function Prototypes

void InitGrid();
void ShowControls();
int countNeighbours();
void updateGrid();
void drawGrid();
void ToggleCellState(Vector2 mouse);
Cell RandomEnum();
void updateControls();
void GliderGun();

// Main Function


int main() {
    InitWindow(screenWidth, screenHeight, title);
    SetTargetFPS(60);

    InitGrid();


    while (!WindowShouldClose()) {
        if (!showedControlsAtStart) {
            while (!IsKeyPressed(KEY_H)){
                ShowControls();
            }
            showedControlsAtStart = true;
        }

        updateControls();

        if (!paused && GetTime() - lastUpdate > updateInterval) {
            BeginDrawing();
            {
                ClearBackground(WHITE);
                updateGrid();
                drawGrid();

            }
            EndDrawing();
            lastUpdate = GetTime();
        }
        else {
            BeginDrawing();
            {
                ClearBackground(WHITE);
                drawGrid();
            }
            EndDrawing();
        }
    }



    return 0;
}

// Function Definitions

Cell RandomEnum(){
    if (GetRandomValue(0,1)){
        return ALIVE;
    } else {
        return DEAD;
    }
}

void InitGrid() {
    for (auto & x : grid) {
        for (auto & y : x) {
            y = DEAD;
        }
    }
}

int countNeighbours(int cellPosX, int cellPosY){
    int neighbourCount = 0;

    for (int x = -1; x <= 1; x++){
        for (int y = -1; y <= 1; y++){
            if (x == 0 && y == 0){
                continue;
            }

            int neighbourX = cellPosX + x;
            int neighbourY = cellPosY + y;

            if (neighbourX < 0 || neighbourY < 0 || neighbourX >= cellCountX || neighbourY >= cellCountY){
                continue;
            }

            if (grid[neighbourX][neighbourY] == ALIVE){
                neighbourCount++;
            }
        }
    }

    return neighbourCount;
}

void updateGrid(){
    Cell newgrid[cellCountX][cellCountY];

    for (int i = 0; i < cellCountX; i++){
        for (int j = 0; j < cellCountY; j++){
            newgrid[i][j] = grid[i][j];
        }
    }

    for (int i = 0; i < cellCountX; i++){
        for (int j = 0; j < cellCountY; j++){

            int ncount = countNeighbours(i, j);


            if (newgrid[i][j] == ALIVE) {
                if (ncount < 2 || ncount > 3) {
                    newgrid[i][j] = DEAD;
                }
            } else {
                if (ncount == 3) {
                    newgrid[i][j] = ALIVE;
                }
            }
        }
    }

    for (int i = 0; i < cellCountX; i++){
        for (int j = 0; j < cellCountY; j++){
            grid[i][j] = newgrid[i][j];
        }
    }
}

void drawGrid(){
    for (int x = 0; x <= cellCountX -1; x++){
        for (int y = 0; y <= cellCountY -1; y++) {
            if (grid[x][y] == ALIVE){
                DrawRectangle(x*cellSize, y*cellSize, cellSize, cellSize, DARKGRAY);
            }
        }
    }
}

void ToggleCellState(Vector2 mouse){
    unsigned int x = (unsigned int) mouse.x / cellSize;
    unsigned int y = (unsigned int) mouse.y / cellSize ;


    if (paused) {
        if (grid[x][y] == DEAD) {
            grid[x][y] = ALIVE;
            return;
        } else {
            grid[x][y] = DEAD;
        }
    }
}

void GliderGun(){
    InitGrid();

    grid[10][14] = ALIVE;
    grid[10][15] = ALIVE;
    grid[11][14] = ALIVE;
    grid[11][15] = ALIVE;
    grid[20][14] = ALIVE;
    grid[20][15] = ALIVE;
    grid[20][16] = ALIVE;
    grid[21][13] = ALIVE;
    grid[21][17] = ALIVE;
    grid[22][12] = ALIVE;
    grid[22][18] = ALIVE;
    grid[23][12] = ALIVE;
    grid[23][18] = ALIVE;
    grid[24][15] = ALIVE;
    grid[25][13] = ALIVE;
    grid[25][17] = ALIVE;
    grid[26][14] = ALIVE;
    grid[26][15] = ALIVE;
    grid[26][16] = ALIVE;
    grid[27][15] = ALIVE;
    grid[30][12] = ALIVE;
    grid[30][13] = ALIVE;
    grid[30][14] = ALIVE;
    grid[31][12] = ALIVE;
    grid[31][13] = ALIVE;
    grid[31][14] = ALIVE;
    grid[32][11] = ALIVE;
    grid[32][15] = ALIVE;
    grid[34][10] = ALIVE;
    grid[34][11] = ALIVE;
    grid[34][15] = ALIVE;
    grid[34][16] = ALIVE;
    grid[44][12] = ALIVE;
    grid[44][13] = ALIVE;
    grid[45][12] = ALIVE;
    grid[45][13] = ALIVE;
}

void ShowControls(){
    BeginDrawing();
    {
        ClearBackground(WHITE);
        DrawText("Controls:", 10, 10, 20, BLACK);
        DrawText("Space: Pause/Unpause", 10, 40, 20, BLACK);
        DrawText("Left Mouse Button: Toggle Cell State", 10, 70, 20, BLACK);
        DrawText("S: Slow down", 10, 100, 20, BLACK);
        DrawText("F: Speed up", 10, 130, 20, BLACK);
        DrawText("D: Default speed", 10, 160, 20, BLACK);
        DrawText("R: Randomize", 10, 190, 20, BLACK);
        DrawText("G: Glider Gun", 10, 220, 20, BLACK);
        DrawText("C: Clear", 10, 250, 20, BLACK);
        DrawText("Esc: Exit", 10, 280, 20, BLACK);
        DrawText("Hold H: Show/Hide this menu", 10, 310, 20, BLACK);
        DrawText("Press H to start. Enjoy!", 10, 340, 20, BLACK);
    } EndDrawing();
}

void updateControls(){
    if (IsKeyPressed(KEY_SPACE)) {
        paused = !paused;
        std::cout << "Toggled pause state to:" << paused << std::endl;
    }

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Vector2 mouse = GetMousePosition();
        ToggleCellState(mouse);

    }


    if (IsKeyPressed(KEY_S)){
        updateInterval += updateIntervalStep;
        if (updateInterval > slowestUpdateInterval){
            updateInterval = slowestUpdateInterval;
        }
    }
    if (IsKeyPressed(KEY_F)){
        updateInterval -= updateIntervalStep;
        if (updateInterval < fastestUpdateInterval){
            updateInterval = fastestUpdateInterval;
        }
    }

    if (IsKeyPressed(KEY_D)){
        updateInterval = 0.1;
    }
    if (IsKeyPressed(KEY_R)){
        InitGrid();
        for (auto & x : grid) {
            for (auto & y : x) {
                y = RandomEnum();
            }
        }
    }

    if (IsKeyPressed(KEY_C)){
        InitGrid();
    }

    if (IsKeyPressed(KEY_G)){
        GliderGun();
    }

    if (IsKeyPressed(KEY_H)){
        while (IsKeyDown(KEY_H)){
            ShowControls();
        }
    }


}