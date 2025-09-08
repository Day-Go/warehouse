#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>

#include "storage.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 400;

int main(void) {
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Warehouse");
  SetTargetFPS(60);

  StorageArea storage_area = storage_area_create((Vector2){200, 100}, 7, 4, 3);
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);

    storage_shelves_draw(&storage_area, 0);
    int mouse_col = GetMousePosition().x / SHELF_SIZE;
    int mouse_row = GetMousePosition().y / SHELF_SIZE;

    EndDrawing();
  }

  return 0;
}
