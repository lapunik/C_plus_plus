#include <iostream>
#include <vector>

const int PLANE_SIZE = 50;

class Point {
public:
    Point(int x, int y) : x(x), y(y) {}
    int getX() const { return x; }
    int getY() const { return y; }
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
    double distanceToOrigin() const {
        return sqrt(x * x + y * y);
    }
    double distanceTo(const Point& other) const {
        int dx = x - other.x;
        int dy = y - other.y;
        return sqrt(dx * dx + dy * dy);
    }
private:
    int x;
    int y;
};

class Shape {
public:
    virtual void draw() const = 0;
};

class Circle : public Shape {
public:
    Circle(Point center, double radius) : center(center), radius(radius) {}
    Point getCenter() const { return center; }
    double getRadius() const { return radius; }
    void setCenter(Point center) { this->center = center; }
    void setRadius(double radius) { this->radius = radius; }
    void draw() const {
        int x0 = center.getX();
        int y0 = center.getY();
        for (int y = y0 - radius; y <= y0 + radius; y++) {
            for (int x = x0 - radius; x <= x0 + radius; x++) {
                if (x >= 0 && x < PLANE_SIZE && y >= 0 && y < PLANE_SIZE) {
                    double d = (x - x0) * (x - x0) + (y - y0) * (y - y0);
                    if (d <= radius * radius) {
                        std::cout << "*";
                    }
                    else {
                        std::cout << " ";
                    }
                }
                else {
                    std::cout << " ";
                }
            }
            std::cout << std::endl;
        }
    }
private:
    Point center;
    double radius;
};

class Rectangle : public Shape {
public:
    Rectangle(Point topLeft, Point bottomRight) : topLeft(topLeft), bottomRight(bottomRight) {}
    Point getTopLeft() const { return topLeft; }
    Point getBottomRight() const { return bottomRight; }
    void setTopLeft(Point topLeft) { this->topLeft = topLeft; }
    void setBottomRight(Point bottomRight) { this->bottomRight = bottomRight; }
    void draw() const {
        int x0 = topLeft.getX();
        int y0 = topLeft.getY();
        int x1 = bottomRight.getX();
        int y1 = bottomRight.getY();
        for (int y = y0; y >= y1; y--) {
            for (int x = x0; x <= x1; x++) {
                if (x >= 0 && x < PLANE_SIZE && y >= 0 && y < PLANE_SIZE) {
                    std::cout << "*";
                }
                else {
                    std::cout << " ";
                }
            }
            std::cout << std::endl;
        }
    }
private:
    Point topLeft;
    Point bottomRight;
};

class Polygon : public Shape
{

private:
    std::vector<Point> points;

public:
    Polygon(const std::vector<Point>& points) : points(points) {}
    std::vector<Point> getPoints() const { return points; }
    void setPoints(const std::vector<Point>& points) { this->points = points; }

    void draw() const {
        int minX = PLANE_SIZE - 1;
        int minY = PLANE_SIZE - 1;
        int maxX = 0;
        int maxY = 0;
        for (const Point& point : points) {
            minX = std::min(minX, point.getX());
            minY = std::min(minY, point.getY());
            maxX = std::max(maxX, point.getX());
            maxY = std::max(maxY, point.getY());
        }
        for (int y = minY; y <= maxY; y++) {
            for (int x = minX; x <= maxX; x++) {
                bool inside = false;
                for (size_t i = 0, j = points.size() - 1; i < points.size(); j = i++) {
                    int xi = points[i].getX();
                    int yi = points[i].getY();
                    int xj = points[j].getX();
                    int yj = points[j].getY();
                    if ((yi > y) != (yj > y)) {
                        double segmentY = (x - xi) * (yj - yi) / (xj - xi) + yi;
                        if (segmentY < y && y <= yi) {
                            inside ^= (xi + (y - yj) / (yi - yj) * (xi - xj) < x);
                        }
                        else if (yi < y && y <= segmentY) {
                            inside ^= (xj + (y - yi) / (yj - yi) * (xj - xi) < x);
                        }
                    }
                    if (x >= 0 && x < PLANE_SIZE && y >= 0 && y < PLANE_SIZE) {
                        std::cout << (inside ? "*" : " ");
                    }
                    else {
                        std::cout << " ";
                    }
                }
                std::cout << std::endl;
            }
        }
    }
};


void drawShapes(const std::vector<Shape*>& shapes) {
    std::vector<std::vector<char>> plane(PLANE_SIZE, std::vector<char>(PLANE_SIZE, ' '));
    for (const Shape* shape : shapes) {
        shape->draw();
    }
    for (int y = PLANE_SIZE - 1; y >= 0; y--) {
        for (int x = 0; x < PLANE_SIZE; x++) {
            std::cout << plane[y][x];
        }
        std::cout << std::endl;
    }
}

int main() {
    Circle circle(Point(10, 10), 5);
    Rectangle rectangle(Point(20, 20), Point(25, 15));
    std::vector<Point> points = { Point(30, 30), Point(35, 30), Point(35, 35), Point(30, 35) };
    Polygon polygon(points);
    std::vector<Shape*> shapes = { &circle, &rectangle, &polygon };
    drawShapes(shapes);
    return 0;
}