#include <iostream>
#include <string>

using namespace std;

struct Point {
    double x;
    double y;
};

struct Circle {
    string tag;
    Point center;
    double radius;
};

//----------------------DO NOT CHANGE ANYTHING ABOVE THIS LINE------------------

double square(double d) {
    return d * d;
}

bool doCirclesIntersect(const Circle &a, const Circle &b) {
    double distanceSquared = square(a.center.x - b.center.x) + square(a.center.y - b.center.y);
    return distanceSquared <= square(a.radius + b.radius) &&
           distanceSquared >= square(a.radius - b.radius);
}

int main()
{
    int circleCount;
    cin >> circleCount;
    Circle *circles = new Circle[circleCount];
    for (int i = 0; i < circleCount; ++i) {
        cin >> circles[i].tag;
        cin >> circles[i].center.x;
        cin >> circles[i].center.y;
        cin >> circles[i].radius;
    }

    for (int i = 0; i < circleCount; ++i) {
        cout << circles[i].tag << ':';
        for (int j = 0; j < circleCount; ++j) {
            if (i != j && doCirclesIntersect(circles[i], circles[j])) {
                cout << ' ' << circles[j].tag;
            }
        }
        cout << endl;
    }
}
