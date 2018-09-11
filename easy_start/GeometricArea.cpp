#include <iostream>
#include <string>

using namespace std;

class Rectangle {
 public:
  float width;
  float length;
  string name;
 public:
  Rectangle() {
    width = 2.0f;
    length = 4.0f;
  }
  Rectangle(float w, float l) {
      width = w;
      length = l;
  }
  Rectangle(const Rectangle &rect) {
      width = rect.width;
      length = rect.length;
  }
  ~Rectangle() {
      std::cout << "destroyed!\n";
  }
  float getArea() {
      return width * length;
  }
};

int main(int argc, char const *argv[]) {
    Rectangle rect1;
    rect1.name = "rect1";
    Rectangle rect2(7.0, 8.0);
    rect2.name = "rect2";
    Rectangle rect3(rect1);
    rect3.name = "rect3";

    std::cout << rect1.name << " : " << rect1.getArea() << std::endl;
    std::cout << rect2.name << " : " << rect2.getArea() << std::endl;
    std::cout << rect3.name << " : " << rect3.getArea() << std::endl;

    return 0;
}
