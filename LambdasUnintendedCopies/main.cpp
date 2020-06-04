#include <iostream>
#include <functional>

void invoke(const std::function<void(void)> &fn)
{
    fn();
}

int main()
{
    int i{ 0 };

    // Increments and prints its local copy of @i.
    auto count{ [i]() mutable {
            std::cout << ++i << '\n';
        } };

    // std::ref(count) ensures count is treated like a reference
    // thus, anything that tries to copy count will actually copy the reference
    // ensuring that only one count exists
    invoke(std::ref(count));
    invoke(std::ref(count));
    invoke(std::ref(count));

    //Rule
    //Standard library functions may copy function objects (reminder: lambdas are function objects).
    //If you want to provide lambdas with mutable captured variables, pass them by reference using
    //std::ref.

//Best practice

//Try to avoid lambdas with states altogether. Stateless lambdas are easier to understand
// and don’t suffer from the above issues, as well as more dangerous issues that arise when
//you add parallel execution.

    return 0;
}
