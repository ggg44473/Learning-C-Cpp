#include "class.h"

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
  stage.objectsP[0] = &top;
  stage.objectsP[1] = &bottom;
  stage.objectsP[2] = &left;
  stage.objectsP[3] = &right;
  stage.objectsP[4] = &ball;


  stage.show();
  return 0;
}
