#include "class.h"
#include <Windows.h>

int main() {
  int objectCount = 0;

  objectCount += 2;
  HWall top, bottom;

  objectCount += 2;
  VWall left, right;

  objectCount++;
  Ball ball;

  Stage stage(objectCount);  // dynamic array objects

  top.y = 0;
  bottom.y = MAXY - 1;
  left.x = 0;
  right.x = MAXX - 1;

  // TODO need to make a function
  stage.objectsPP[0][0] = &top;
  stage.objectsPP[0][1] = &bottom;
  stage.objectsPP[0][2] = &left;
  stage.objectsPP[0][3] = &right;
  stage.objectsPP[0][4] = &ball;

  int stepCount = MAXSTEP;
  do {
  stage.clear();
  stage.stepNext(objectCount);
  stage.show();
  Sleep(200);
  } while (stepCount--);
  return 0;
}
