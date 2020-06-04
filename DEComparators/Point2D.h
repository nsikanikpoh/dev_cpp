#ifndef POINT2D_H_INCLUDED
#define POINT2D_H_INCLUDED

#include <iostream>
#include <cmath>

class Point2D
{
private:
    double m_x;
    double m_y;

public:
    Point2D(double x = 0.0, double y = 0.0) : m_x{ x }, m_y{ y }
    {
    }

    int getX() const
    {
        return m_x;
    }
    int getY() const
    {
        return m_y;
    }

    friend std::ostream& operator<< (std::ostream &out, const Point2D &point);

    void print()
    {
        std::cout << "Point2d(" << m_x << ", " << m_y << ")\n";
    }


    double distanceTo(const Point2D &p) const
    {
        return sqrt((m_x - p.m_x)*(m_x - p.m_x) + (m_y - p.m_y)*(m_y - p.m_y));
    }

    friend double distanceFrom(const Point2D &p, const Point2D &p2);

};

std::ostream& operator<< (std::ostream &out, const Point2D &point)
{
    // Since operator<< is a friend of the Point class, we can access Point's members directly.
    out << "Point(" << point.m_x << ", " << point.m_y << ")"; // actual output done here

    return out; // return std::ostream so we can chain calls to operator<<
}

double distanceFrom(const Point2D &p, const Point2D&p2)
{
    return sqrt((p.m_x - p2.m_x)*(p.m_x - p2.m_x) + (p.m_y - p2.m_y)*(p.m_y - p2.m_y));
}



#endif // POINT2D_H_INCLUDED
