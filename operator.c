#include "operator.h"

void operator_move_to_target(Operator *operator, Vector2 target) {}

void operator_draw(Operator *operator) {
  DrawCircle(operator->position.x, operator->position.y, operator->radius,
             GREEN);
}
