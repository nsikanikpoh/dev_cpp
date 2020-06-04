#include <iostream>
#include "Point2D.h"
#include <queue>

using namespace std;


class LeftRight
{
// a left-right comparator
public:
    bool operator()(const Point2D& p, const Point2D& q) const
    {
        return p.getX() < q.getX();
    }
};
class BottomTop
{
// a bottom-top comparator
public:
    bool operator()(const Point2D& p, const Point2D& q) const
    {
        return p.getY() < q.getY();
    }
};

// element type and comparator
template <typename E, typename C>
void printSmaller(const E& p, const E& q, const C& isLess)
{
    cout << (isLess(p, q) ? p : q) << endl; // print the smaller of p and q
}


int main()
{
    Point2D p(1.3, 5.7), q(2.5, 0.6);//two points
    LeftRight leftRight;//a left-right comparator
    BottomTop bottomTop;//a bottom-top comparator
    printSmaller(p, q, leftRight);//outputs: (1.3, 5.7)
    printSmaller(p, q, bottomTop);//outputs: (2.5, 0.6)

    priority_queue<int> p1;// a priority queue of integers


// a priority queue of points with left-to-right order
    priority_queue<Point2D, vector<Point2D>, LeftRight> p2;
    p2.push( Point2D(8.5, 4.6) );
    p2.push( Point2D(1.3, 5.7) );
    p2.push( Point2D(2.5, 0.6) );
    cout << p2.top() << endl;
    p2.pop();
    cout << p2.top() << endl;
    p2.pop();
    cout << p2.top() << endl;
    p2.pop();

// add three points to p2
// output: (8.5, 4.6)
// output: (2.5, 0.6)
// output: (1.3, 5.7)
    return 0;
}
