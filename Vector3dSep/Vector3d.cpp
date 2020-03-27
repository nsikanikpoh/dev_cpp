
// Member functions of the Vector3d class defined here

#include <iostream>
#include "Vector3d.h" // Vector3d class declared in this file

void Vector3d::print()
{
    std::cout << "Vector(" << m_x << " , " << m_y << " , " << m_z << ")\n";
}
