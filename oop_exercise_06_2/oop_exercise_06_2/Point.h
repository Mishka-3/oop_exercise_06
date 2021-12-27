#pragma once

#include <numeric>
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

template <typename T>
struct Point {
    T x;
    T y;
};
template <typename T>
Point<T> operator+(Point<T> left, Point<T> right) {
     Point<T> p;
    p.x = left.x+right.x;
    p.y = left.y+right.y;
        return p;

}

template <typename T>
 Point<T> operator+( Point<T> left, int right) {
     Point<T> p;
    p.x = left.x+right;
    p.y = left.y+right;
        return p;

}

template <typename T>
 Point<T> operator-( Point<T> left,  Point<T> right) {
     Point<T> p;
    p.x = left.x-right.x;
    p.y = left.y-right.y;
        return p;

}

template <typename T>
 Point<T> operator-(Point<T> left, double right) {
     Point<T> p;
    p.x = left.x-right;
    p.y = left.y-right;
        return p;

}

template <typename T>
 Point<T> operator/( Point<T> left, double right) {
    Point<T> p;
    p.x = left.x/right;
    p.y = left.y/right;
        return p;

}

template <typename T>
 Point<T> operator*(Point<T> left, double right) {
     Point<T> p;
    p.x = left.x*right;
    p.y = left.y*right;
    return p;
}
template <typename T>
double length( Point<T> left,  Point<T> right) {
    return sqrt((left.x-right.x)*(left.x-right.x)+(left.y-right.y)*(left.y-right.y));
}

template <typename T>
bool isTrapezoid(T xa, T xb, T xc, T xd, T ya, T yb, T yc, T yd) {
    bool result = false;
    long double l = abs(sqrt((xc - xa) * (xc - xa) + (yc - ya) * (yc - ya)));
    long double m = abs(sqrt((xd - xb) * (xd - xb) + (yd - yb) * (yd - yb)));
    if (((xc - xb) * (yd - ya) == (xd - xa) * (yc - yb)) || ((xb - xa) * (yc - yd) == (xc - xd) * (yb - ya))) {
        if (((xb - xa) * (yc - yd) == (xc - xd) * (yb - ya)) && ((xc - xb) * (yd - ya) == (xd - xa) * (yc - yb)))
            if (l == m) {
                std::cout << "notTrapezoid" << "\n";
                return result;
            }
            else {
                std::cout << "notTrapezoid" << "\n";
                return result;
            }
        else {
            std::cout << "Trapezoid" << "\n";
            result = true;
            return result;
        }
    }
    else {
        std::cout << "notTrapezoid" << "\n";
        return result;
    }
    return result;
}

template <typename T>
std::ostream& operator << (std::ostream& os, const Point<T>& p) {
    return os << p.x << " " << p.y;
}

template <typename T>
std::istream& operator >> (std::istream& is, Point<T>& p) {
    return is >> p.x >> p.y;
}