/*
 * File: point.h
 * -------------
 * This interface exports a class representing an integer-valued x-y pair.
 */

#define _USE_MATH_DEFINES

#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Point
{
private:
    int x;
    int y;

    friend ostream &operator<<(ostream &os, const Point &pt);
    friend string operator<<(string &os, const Point &pt);
    friend Point abs(Point p);

public:
    Point(int a = 0, int b = 0) : x{a}, y{b} {}
    int getX() const{ return x; }
    int getY() const { return y; }
    int distanceFrom(const Point &p) const;

    Point &operator=(const Point &p2);
    Point &operator+=(const Point &p2);
    Point &operator-=(const Point &p2);
    Point &operator+=(const int &num);
    Point &operator-=(const int &num);
    Point &operator*=(const Point &p2);
    Point &operator/=(const Point &p2);
    Point &operator*=(const int &num);
    Point &operator/=(const int &num);
    bool operator==(const Point &p2) const { return (x == p2.x && y == p2.y); }
    bool operator!=(const Point &p2) const { return !(*this == p2); }
    bool operator==(const int &num) const { return *this == Point(num, num); }
    bool operator!=(const int &num) const { return !(*this == num); }
    bool operator>(const Point &p2) const { return x > p2.x && y > p2.y; }
    bool operator<(const Point &p2) const { return x < p2.x && y < p2.y; }
    bool operator>(const int num) const { return x > num && y > num; }
    bool operator<(const int num) const { return x < num && y < num; }
    bool operator>=(const Point &p2) const { return !(*this < p2); }
    bool operator<=(const Point &p2) const { return !(*this > p2); }
    bool operator>=(const int num) const { return !(*this < Point(num, num)); }
    bool operator<=(const int num) const { return !(*this > Point(num, num)); }
    Point operator+(const Point p2) const { return Point(x + p2.x, y + p2.y); }
    Point operator-(const Point p2) const { return Point(x - p2.x, y - p2.y); }
    Point operator*(const Point p2) const { return Point(x * p2.x, y * p2.y); }
    Point operator/(const Point p2) const { return Point(x / p2.x, y / p2.y); }
    Point operator+(const int num) const { return Point(x + num, y + num); }
    Point operator-(const int num) const { return Point(x - num, y - num); }
    Point operator*(const int num) const { return Point(x * num, y * num); }
    Point operator/(const int num) const { return Point(x / num, y / num); }

    Point onCircle(const int r, size_t deg) { return Point(x + sin(deg * M_PI / 180) * r, y + cos(deg * M_PI / 180) * r); }
    size_t getDegree(const Point p);
};

ostream &operator<<(ostream &os, const Point &pt);

#endif