#include "storage.h"
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

StorageArea storage_area_create(Vector2 start_pos, int n_cols, int n_rows,
                                int n_lvls) {
  StorageArea storage_area;
  storage_area.n_cols = n_cols;
  storage_area.n_rows = n_rows;
  storage_area.n_lvls = n_lvls;
  storage_area.shelves = malloc(n_cols * n_rows * n_lvls * sizeof(Shelf));

  for (int lvl = 0; lvl < n_lvls; lvl++) {
    for (int col = 0; col < n_cols; col++) {
      for (int row = 0; row < n_rows; row++) {
        float x = start_pos.x + SHELF_SIZE * col + COL_SPACING * col;
        float y = start_pos.y + SHELF_SIZE * row + ROW_SPACING * row;
        printf("%i, %i, %i\n", lvl, col, row);
        printf("%f, %f\n\n", x, y);
        int idx = lvl * (n_rows * n_cols) + row * n_cols + col;
        storage_area.shelves[idx] = (Shelf){.bin = "A",
                                            .shape = {.x = x,
                                                      .y = y,
                                                      .width = SHELF_SIZE,
                                                      .height = SHELF_SIZE},
                                            .contents = 0,
                                            .level = lvl};
      }
    }
  }

  return storage_area;
}

void storage_shelves_draw(StorageArea *storage_area, int lvl) {
  for (int col = 0; col < storage_area->n_cols; col++) {
    for (int row = 0; row < storage_area->n_rows; row++) {
      int idx = lvl * (storage_area->n_rows * storage_area->n_cols) +
                row * storage_area->n_cols + col;
      if (storage_area->shelves[idx].level != lvl) {
        continue;
      }

      DrawRectangleRec(storage_area->shelves[idx].shape, LIGHTGRAY);
    }
  }
}

void storage_area_destroy(StorageArea storage_area) {}
