#include <iostream>

using namespace std;

#define MAXX 25
#define MAXY 80
#define MAXSTEP 100

class Vector {
 public:
  int x, y;
  Vector() : x(0), y(0){};
  Vector(int a, int b) : x(a), y(b){};
};

class Coord : public Vector {};

class Object;

class Stage {
 public:
  char canvas[MAXX][MAXY];
  Object ***objectsPP;

  Stage(int);
  ~Stage();
  void clear() {
    for (int i = 0; i < MAXX; i++) {
      for (int j = 0; j < MAXY; j++) {
        canvas[i][j] = ' ';
      }
    }
  };
  void show() {
    system("cls");
    for (int i = 0; i < MAXX; i++) {
      for (int j = 0; j < MAXY; j++) {
        cout << canvas[i][j];
      }
    }
  };
  void stepNext(int);
};

class Object {
 public:
  virtual void draw(Stage &stage){};
  virtual void stepNext(){};
  virtual void collide(Object *objects){};
};

class VWall : public Object {
 public:
  int x;
  void draw(Stage &stage) {
    for (int y = 1; y < MAXY - 1; y++) {
      stage.canvas[x][y] = '@';
    }
  };
};

class HWall : public Object {
 public:
  int y;
  void draw(Stage &stage) {
    for (int x = 1; x < MAXX - 1; x++) {
      stage.canvas[x][y] = '@';
    }
  };
};

class Ball : public Object {
 public:
  Vector movement;
  Coord position;
  char symbol;

  Ball() {
    movement.x = 1;
    movement.y = 1;
    position.x = MAXX / 2 - 1;
    position.y = MAXY / 2 - 1;
    symbol = '$';
  };
  void draw(Stage &stage) { stage.canvas[position.x][position.y] = symbol; };
  void stepNext() {
    position.x += movement.x;
    position.y += movement.y;
  };
  void collide(Object *objects) {
    VWall *wx = dynamic_cast<VWall *>(objects);
    if (wx != NULL) {
      if ((position.x + movement.x) == wx->x) {
        movement.x = -movement.x;
      }
    }
    HWall *wy = dynamic_cast<HWall *>(objects);
    if (wy != NULL) {
      if ((position.y + movement.y) == wy->y) {
        movement.y = -movement.y;
      }
    }
  };
};

class Corner : public Object {};

Stage::Stage(int objectCount) { **objectsPP = new Object[objectCount]; }
Stage::~Stage() { delete[](*objectsPP); }
void Stage::stepNext(int objectCount) {
  for (int i = 0; i < objectCount; i++) {
    for (int j = 0; j < objectCount; j++) {
      if ( i != j) {
        (*objectsPP)[i]->collide((*objectsPP)[j]);
      }
    }
  }

  for (int n = 0; n < objectCount; n++) {
    (*objectsPP)[n]->stepNext();
    (*objectsPP)[n]->draw(*this);
  }
};