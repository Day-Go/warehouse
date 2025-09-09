#include "raylib.h"

#define SHELF_SIZE 25
#define COL_GAP 50
#define COL_SPACING 5
#define ROW_SPACING 5

typedef struct {
  char *bin;
  Rectangle shape;
  int level;
  int contents;
} Shelf;

typedef struct {
  Shelf *shelves;
  int n_cols;
  int n_rows;
  int n_lvls;
} StorageArea;

StorageArea storage_area_create(Vector2 start_pos, int n_cols, int n_rows,
                                int n_lvls);

void storage_area_destroy(StorageArea storage_area);
Shelf *storage_area_mouse_entered(StorageArea *storage_area, Vector2 mouse_pos);
void storage_shelves_draw(StorageArea *storage_area, int lvl);
void storage_shelf_highlight(Shelf *shelf);
