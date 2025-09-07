#include "grid.h"
#include "raylib.h"
#include <stdlib.h>

int grid_width;
int grid_height;

struct Cell **grid_create(int width, int height) {
  grid_width = width / CELL_SIZE;
  grid_height = height / CELL_SIZE;
  struct Cell **grid = malloc(grid_height * sizeof(struct Cell *));
  for (int row = 0; row < grid_height; row++) {
    grid[row] = malloc(grid_width * sizeof(struct Cell));
    for (int col = 0; col < grid_width; col++) {
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

void grid_draw(struct Cell **grid, int width, int height) {
  for (int row = 0; row < grid_height; row++) {
    DrawLine(grid[row][0].rect.x, grid[row][0].rect.y,
             grid[row][grid_width - 1].rect.x + CELL_SIZE,
             grid[row][grid_width - 1].rect.y, LIGHTGRAY);
  }
  for (int col = 0; col < grid_width; col++) {
    DrawLine(grid[0][col].rect.x, grid[0][col].rect.y,
             grid[grid_height - 1][col].rect.x,
             grid[grid_height - 1][col].rect.y + CELL_SIZE, LIGHTGRAY);
  }
}
