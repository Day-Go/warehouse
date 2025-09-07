#include "raylib.h"
#define CELL_SIZE 20

enum cell_state { EMPTY, FULL };

struct Cell {
  Rectangle rect;
  enum cell_state state;
};

struct Cell **grid_create(int width, int height);
void grid_draw(struct Cell **grid, int width, int height);
