

#ifndef VECTOR3D_H_INCLUDED
#define VECTOR3D_H_INCLUDED

#include "Point3d.h" // for declaring Point3d::moveByVector() as a friend

class Vector3d
{
    private:
        double m_x;
        double m_y;
        double m_z;

    public:
        Vector3d(double x = 0.0, double y = 0.0, double z = 0.0) : m_x(x), m_y(y), m_z(z) {}

        void print();
        friend void Point3d::moveByVector(const Vector3d &v);
};


#endif // VECTOR3D_H_INCLUDED
