#include <iostream>

using namespace std;

// abstract class
class Shape {
public:
    virtual int getArea() = 0;
};


/* Even though square is a type of Rectangle, one should expect a Sqaure to be
 * usable, where a Rectangle is used. If we'd use a Square where a Rectangle is 
 * expected, then it couldn't accommodate the variable side length of a Rectangle
 * additionally we'd need to override the setHeight and setWidth on the Rectangle,
 * which we don't need to do right now */

class Square : public Shape {
protected:
    int height; 

public:
    virtual int getArea() override {
        return height*height;
    }

    void setHeight(int h) {
        height = h;
    }
};

class Rectangle : public Square {
protected:
    int width;

public:
    virtual int getArea() override {
        return height * width;
    }

    void setWidth(int w) {
        width = w;
    }
};

int main() {

    Square sq;
    Rectangle rect;
    sq.setHeight(5);
    cout << sq.getArea() << endl;
    rect.setHeight(5);
    rect.setWidth(6);
    cout << rect.getArea() << endl;

}
