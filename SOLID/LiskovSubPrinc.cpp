//
// Created by David on 28/10/2021.
//

#include "LiskovSubPrinc.h"
#include <iostream>

class Rectangle
{
protected:
    int width, height;
public:
    Rectangle(int width, int height): width(width), height(height){};

    int getWidth() const {
        return width;
    }

    virtual void setWidth(int width) {
        Rectangle::width = width;
    }

    int getHeight() const {
        return height;
    }

    virtual void setHeight(int height) {
        Rectangle::height = height;
    }

    int area() const {return width * height;}
};

 class Square : public Rectangle
{
public:
    Square(int size): Rectangle(size, size) {}

    //Violates Liskov substitution principle - have a func that takes a base class,
    // and class that takes from it should be able to be substituted.
    void setWidth(int width) override {
        this->width = this->height = width;
    }

    void setHeight(int height) override {
        this->height = this->width = height;
    }
};

static void process(Rectangle &r)
{
    int w = r.getWidth();
    r.setHeight(10);

    std::cout<< "expected Area ="<< (w*10) << ", got" << r.area() << std::endl;

}

struct RectangleFactory
{
    //Solution -> Square should be Derived from the rect class
    static Rectangle create_rectagle(int w, int h);
    static Rectangle create_square(int size);
};

static void pseudoMain()
{
    //Liskov Substitute Principle ------
    Rectangle r{3,4};
    process(r);

    Square sq{5};
    process(sq);

}