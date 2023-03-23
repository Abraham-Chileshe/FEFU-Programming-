#include <iostream>
#include <cmath>
#define line cout<<"\n------------------------------\n";

using namespace std;

class Point {
public:
    double x, y, z;

    Point(double x, double y, double z) : x(x), y(y), z(z) {}

    double distance(Point other) {
        return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y) + (z - other.z) * (z - other.z));
    }

    //Multiplication of Point
    Point operator*(double num) {
        return Point(x * num, y * num, z * num);
    }

    //Addition of Points
    Point operator+(Point other) {
        return Point(x + other.x, y + other.y, z + other.z);
    }

    //Division of Points
    Point operator/(double num) {
        return Point(x / num, y / num, z / num);
    }
};

class Vector {
public:
    Point pt;

    Vector(Point pt) : pt(pt) {
        //assertion not needed in C++
    }

    double length() {
        return sqrt(pt.x * pt.x + pt.y * pt.y + pt.z * pt.z);
    }

    double operator*(Vector other) {
        return pt.x * other.pt.x + pt.y * other.pt.y + pt.z * other.pt.z;
    }

    Vector operator*(double num) {
        return Vector(Point(pt.x * num, pt.y * num, pt.z * num));
    }

    void print() {
        cout << pt.x << " " << pt.y << " " << pt.z << endl;
    }

    Vector add(Vector other) {
        return Vector(Point(pt.y * other.pt.z - pt.z * other.pt.y,
                             -(pt.x * other.pt.z - pt.z * other.pt.x),
                             pt.x * other.pt.y - pt.y * other.pt.x));
    }
};

class Camera {
public:
    Point position, look_at, look_dir;
    double fov;
    bool draw;

    Camera(Point position, Point look_at, Point look_dir, double fov, bool draw)
        : position(position), look_at(look_at), look_dir(look_dir), fov(fov), draw(draw) {}
};

class Object {
public:

};

int main() {
    // Test Point class
    Point p1(1, 2, 3);
    Point p2(4, 5, 6);
    double dist = p1.distance(p2);
    cout << "Distance between p1 and p2: " << dist << endl;
    std::line;

    Point p3 = p1 * 2;
    cout << "p1 * 2 = (" << p3.x << ", " << p3.y << ", " << p3.z << ")" << endl;
    std::line;

    Point p4 = p1 + p2;
    cout << "p1 + p2 = (" << p4.x << ", " << p4.y << ", " << p4.z << ")" << endl;
    std::line;

    Point p5 = p1 / 2;
    cout << "p1 / 2 = (" << p5.x << ", " << p5.y << ", " << p5.z << ")" << endl;
    std::line;

    // Test Vector class
    Vector v1(Point(1, 2, 3));
    Vector v2(Point(4, 5, 6));
    double dot_product = v1 * v2;
    cout << "Dot product of v1 and v2: " << dot_product;
    std::line;
    Vector v3 = v1 * 2;
    cout << "v1 * 2 = ";
    v3.print();

    Vector v4 = v1.add(v2);
    cout << "v1 + v2 = ";
    v4.print();
    std::line;

    double length = v1.length();
    cout << "Length of v1: " << length << endl;
    std::line;

    // Test Camera class
    Point position(0, 0, 0);
    Point look_at(0, 0, 1);
    Point look_dir(0, 1, 0);
    double fov = 45.0;
    bool draw = true;

    Camera camera(position, look_at, look_dir, fov, draw);

    cout << "Camera position: (" << camera.position.x << ", " << camera.position.y << ", " << camera.position.z << ")" << endl;
    cout << "Camera look_at: (" << camera.look_at.x << ", " << camera.look_at.y << ", " << camera.look_at.z << ")" << endl;
    cout << "Camera look_dir: (" << camera.look_dir.x << ", " << camera.look_dir.y << ", " << camera.look_dir.z << ")" << endl;
    cout << "Camera field of view: " << camera.fov << endl;
    cout << "Camera draw: " << camera.draw << endl;


    return 0;
}
