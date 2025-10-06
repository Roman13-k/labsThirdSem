#include <iostream>
#include <cmath>
#define M_PI 3.14159265358979323846

using namespace std;

class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void display() const = 0;
    virtual bool isPoligon() const = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override {
        return width * height;
    }

    double perimeter() const override {
        return 2 * (width + height);
    }

    void display() const override {
        cout << "Rectangle: Width = " << width
            << ", Height = " << height
            << ", Area = " << area()
            << ", Perimeter = " << perimeter()
            << ", Polygon = " << (isPoligon() ? "Yes" : "No")
            << endl;
    }

    bool isPoligon() const override {
        return true;
    }
};

class Triangle : public Shape {
private:
    double a, b, c;
public:
    Triangle(double side1, double side2, double side3)
        : a(side1), b(side2), c(side3) {
        if (a + b <= c || a + c <= b || b + c <= a) {
            throw invalid_argument("Invalid triangle sides");
        }
    }

    double area() const override {
        double p = perimeter() / 2.0;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    double perimeter() const override {
        return a + b + c;
    }

    void display() const override {
        cout << "Triangle: a = " << a
            << ", b = " << b
            << ", c = " << c
            << ", Area = " << area()
            << ", Perimeter = " << perimeter()
            << ", Polygon = " << (isPoligon() ? "Yes" : "No")
            << endl;
    }

    bool isPoligon() const override {
        return true;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return M_PI * radius * radius;
    }

    double perimeter() const override {
        return 2 * M_PI * radius;
    }

    void display() const override {
        cout << "Circle: Radius = " << radius
            << ", Area = " << area()
            << ", Perimeter = " << perimeter()
            << ", Polygon = " << (isPoligon() ? "Yes" : "No")
            << endl;
    }

    bool isPoligon() const override {
        return false;
    }
};

int main() {
    Shape* shapes[] = {
        new Rectangle(10, 13.5),
        new Triangle(3, 4, 5),
        new Circle(4)
    };

    for (Shape* shape : shapes) {
        shape->display();
    }

    for (Shape* shape : shapes) {
        delete shape;
    }

    return 0;
}
