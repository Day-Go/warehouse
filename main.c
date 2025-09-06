#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

int main(void) {
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Warehouse");

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);
    EndDrawing();
  }

  return 0;
}
