#include <iostream>

using namespace std;

#define MAXX 25
#define MAXY 80

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
  Object **objectsP;

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
};

class Object {
 public:
  virtual void draw(Stage &stage){};
  virtual void stepNext(){};
  virtual void collide(Object *op){};
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
};

class Corner : public Object {};

Stage::Stage(int objectCount) { *objectsP = new Object[objectCount]; };
Stage::~Stage() { delete [] (*objectsP) };
