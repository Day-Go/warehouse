#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>

#include "grid.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

int main(void) {
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Warehouse");
  SetTargetFPS(60);

  struct Cell **grid = grid_create(WINDOW_WIDTH, WINDOW_HEIGHT);
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);
    grid_draw(grid, WINDOW_WIDTH, WINDOW_HEIGHT);

    int mouse_col = GetMousePosition().x / CELL_SIZE;
    int mouse_row = GetMousePosition().y / CELL_SIZE;

    DrawRectangle(grid[mouse_row][mouse_col].rect.x,
                  grid[mouse_row][mouse_col].rect.y,
                  grid[mouse_row][mouse_col].rect.width,
                  grid[mouse_row][mouse_col].rect.height, YELLOW);

    EndDrawing();
  }

  return 0;
}
