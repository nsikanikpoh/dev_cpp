

#ifndef POINT3D_H_INCLUDED
#define POINT3D_H_INCLUDED

class Vector3d; // forward declaration for class Vector3d for function moveByVector()

class Point3d
{
    private:
        double m_x;
        double m_y;
        double m_z;

    public:
        Point3d(double x = 0.0, double y = 0.0, double z = 0.0) : m_x(x), m_y(y), m_z(z) {}

        void print();
        void moveByVector(const Vector3d &v); // forward declaration above needed for this line
};


#endif // POINT3D_H_INCLUDED
