#include <stdio.h>

enum _GeoType { Circle, Rectangle, Triangle };
typedef enum _GeoType GeoType;

typedef float (*GetArea)(void *);

struct _GeoObject {
  GeoType obj_type;
  GetArea get_area;
  float radius;
  float width, lenth;
  float base, height;
};
typedef struct _GeoObject GeoObject;

float get_area_circle(int type, float radius);
float get_area_reactangle(int type, float width, float lenth);
float get_area_triangle(int type, float base, float height);
float get_area_by_type(GeoObject *obj);

int main(int argc, char const *argv[]) {
  GeoObject objects[3];

  objects[0].obj_type = Circle;
  objects[0].radius = 2.0f;

  objects[1].obj_type = Rectangle;
  objects[1].width = 3.0f;
  objects[1].lenth = 4.1f;

  objects[2].obj_type = Triangle;
  objects[2].base = 8.2f;
  objects[2].height = 2.0f;

  for (int i = 0; i < 3; i++) {
    objects[i].get_area = (GetArea)get_area_by_type;
    // obj_type is int, cannot print its tag.
    printf("type = %d\n", objects[i].obj_type);
    // round up float.
    // %x.yf means x digits before the point, y digits after that.
    printf("type = %0.1f\n\n", objects[i].get_area(objects + i));
  }

  return 0;
}

float get_area_circle(int type, float radius) {
  return radius * radius * 3.1415;
}

float get_area_reactangle(int type, float width, float lenth) {
  return width * lenth;
}

float get_area_triangle(int type, float base, float height) {
  return base * height / 2;
}

float get_area_by_type(GeoObject *obj) {
  int type;
  float area;
  type = obj->obj_type;
  if (type == Circle) {
    area = get_area_circle(type, obj->radius);
  } else if (type == Rectangle) {
    area = get_area_reactangle(type, obj->width, obj->lenth);
  } else if (type == Triangle) {
    area = get_area_triangle(type, obj->base, obj->height);
  }
  return area;
}