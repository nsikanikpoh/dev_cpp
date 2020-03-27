// Member functions of the Point3d class defined here

#include <iostream> // for std::cout
#include "Point3d.h" // Point3d class declared in this
#include "Vector3d.h" // for the parameter of the function moveByVector()

void Point3d::moveByVector(const Vector3d &v)
{
    // Add the vector components to the corresponding point coordinates
    m_x += v.m_x;
    m_y += v.m_y;
    m_z += v.m_z;
}

void Point3d::print()
{
    std::cout << "Point(" << m_x << " , " << m_y << " , " << m_z << ")\n";
}
