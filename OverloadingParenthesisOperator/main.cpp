#include <iostream>
#include <cassert> // for assert()

class Matrix
{
private:
    double data[4][4]{};

public:
    double& operator()(int row, int col);
    const double& operator()(int row, int col) const; // for const objects
    void operator()();
};

double& Matrix::operator()(int row, int col)
{
    assert(col >= 0 && col < 4);
    assert(row >= 0 && row < 4);

    return data[row][col];
}

const double& Matrix::operator()(int row, int col) const
{
    assert(col >= 0 && col < 4);
    assert(row >= 0 && row < 4);

    return data[row][col];
}
void Matrix::operator()()
{
    // reset all elements of the matrix to 0.0
    for (int row{ 0 }; row < 4; ++row)
        for (int col{ 0 }; col < 4; ++col)
            data[row][col] = 0.0;
}

int main()
{
    Matrix matrix;
    matrix(1, 2) = 4.5;
    matrix(); // erase matrix
    std::cout << matrix(1, 2) << '\n';
    return 0;
}
