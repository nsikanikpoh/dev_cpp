#include <iostream>

#include <string>
class Course
{
private:
    std::string m_name;
    Course *m_prerequisite;

public:
    Course(std::string &name, Course *prerequisite=nullptr):
        m_name(name), m_prerequisite(prerequisite)
    {
    }
};


using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
