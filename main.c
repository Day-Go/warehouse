#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>

#include "operator.h"
#include "storage.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 400;

int main(void) {
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Warehouse");
  SetTargetFPS(60);

  StorageArea storage_area = storage_area_create((Vector2){200, 70}, 10, 5, 3);

  Operator op1 = {10.0f, {.x = 50.0f, .y = 350.0f}, IDLE};

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);

    storage_shelves_draw(&storage_area, 0);

    Vector2 mouse_pos = GetMousePosition();
    Shelf *hovered = storage_area_mouse_entered(&storage_area, mouse_pos);

    if (hovered != NULL) {
      storage_shelf_highlight(hovered);
    }

    operator_draw(&op1);

    EndDrawing();
  }

  return 0;
}
