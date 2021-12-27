#pragma once
#include "Point.h"
#include <vector>
template <typename T>

class Trapezoid {
    public:
    Point<T> points[4];
    Trapezoid<T>() = default;
    Trapezoid(Point<T> p1, Point<T> p2, Point<T> p3, Point<T> p4);
    double getSquare() const;
    Point<T> getCenter() const;
    bool scan(std::istream &is);
    void print(std::ostream& os) const;
    
}; 


template <typename T>
Trapezoid<T>::Trapezoid(Point<T> p1, Point<T> p2, Point<T> p3, Point<T> p4) {
    points[0] = p1;
    points[1] = p2;
    points[2] = p3;
    points[3] = p4; 

    }

    template <typename T>
double Trapezoid<T>::getSquare() const {
    
	return 0.5 * length(this->points[0],this->points[1])*length(this->points[0],this->points[3]);
}
template <typename T>
void Trapezoid<T>::print(std::ostream& os) const {
    for (int i = 0; i < 4; ++i) {
        os << "(" << this->points[i] <<  ") ";
    }
    os << std::endl;
}
template <typename T>
bool Trapezoid<T>::scan(std::istream &is) {
    Point<T> p1,p2,p3,p4;
    bool result = false;
    is >> p1 >> p2 >> p3 >> p4;
    *this = Trapezoid(p1,p2,p3,p4);
    if (!isTrapezoid(p1.x, p2.x, p3.x, p4.x, p1.y, p2.y, p3.y, p4.y)) {
        return result;
    }
    else
        result = true;
    return result;
}

template <typename T>
Point<T> Trapezoid<T>::getCenter() const {

    Point<T> p;
    p.x = 0;
    p.y = 0;
    for (size_t i = 0; i < 4; ++i) {
        p = p+(points[i]/4);
    }
    return p;
}

