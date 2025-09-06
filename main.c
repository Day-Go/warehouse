#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int CELL_SIZE = 20;
const int GRID_WIDTH = WINDOW_WIDTH / CELL_SIZE;
const int GRID_HEIGHT = WINDOW_HEIGHT / CELL_SIZE;

enum cell_state { EMPTY, FULL };

struct Cell {

  Rectangle rect;
  enum cell_state state;
};

struct Cell **create_grid(void) {
  struct Cell **grid = malloc(GRID_HEIGHT * sizeof(struct Cell *));
  for (int row = 0; row < GRID_HEIGHT; row++) {
    grid[row] = malloc(GRID_WIDTH * sizeof(struct Cell));
    for (int col = 0; col < GRID_WIDTH; col++) {
      int top_left_x = col * CELL_SIZE;
      int top_left_y = row * CELL_SIZE;
      struct Cell cell = (struct Cell){.rect.x = top_left_x,
                                       .rect.y = top_left_y,
                                       .rect.width = CELL_SIZE,
                                       .rect.height = CELL_SIZE,
                                       .state = EMPTY};
      grid[row][col] = cell;
    }
  }

  return grid;
}

void draw_grid(struct Cell **grid) {
  for (int row = 0; row < GRID_HEIGHT; row++) {
    DrawLine(grid[row][0].rect.x, grid[row][0].rect.y,
             grid[row][GRID_WIDTH - 1].rect.x + CELL_SIZE,
             grid[row][GRID_WIDTH - 1].rect.y, LIGHTGRAY);
  }
  for (int col = 0; col < GRID_WIDTH; col++) {
    DrawLine(grid[0][col].rect.x, grid[0][col].rect.y,
             grid[GRID_HEIGHT - 1][col].rect.x,
             grid[GRID_HEIGHT - 1][col].rect.y + CELL_SIZE, LIGHTGRAY);
  }
}

int main(void) {
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Warehouse");
  SetTargetFPS(60);

  struct Cell **grid = create_grid();
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);
    draw_grid(grid);

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
