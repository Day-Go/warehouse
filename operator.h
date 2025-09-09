#include "raylib.h"

typedef enum { IDLE, MOVING, LOADING, UNLOADING } OperatorState;

typedef struct {
  float radius;
  Vector2 position;
  OperatorState state;
} Operator;

void operator_move_to_target(Operator *operator, Vector2 target);
void operator_draw(Operator *operator);
