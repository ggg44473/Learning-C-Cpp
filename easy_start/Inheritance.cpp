#include <iostream>

using namespace std;

class One {
    private:
        int x;
    public:
        void setX(int a) {x=a;};
        void showX() {cout << "x = " << x << endl;};
};

class Two: public One {
    private:
        int y;
    public:
        void setXY(int a, int b) {setX(a); y=b;};
        void showXY() { showX(); cout << "y = " << y << endl;};
};

int main(int argc, char const *argv[])
{
    One obj1;
    obj1.setX(10);
    obj1.showX();
    One obj111;
    obj111.setX(111111);
    obj111.showX();

    Two obj2;
    obj2.setXY(5, 7);
    obj2.showX();
    obj2.showXY();

    obj1.showX();
    return 0;
}
