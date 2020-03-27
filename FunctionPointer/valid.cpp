// function prototypes
int foo();
double goo();
int hoo(int x);

// function pointer assignments
int (*fcnPtr1)() = foo; // okay
int (*fcnPtr2)() = goo; // wrong -- return types don't match!
double (*fcnPtr4)() = goo; // okay
fcnPtr1 = hoo; // wrong -- fcnPtr1 has no parameters, but hoo() does
int (*fcnPtr3)(int) = hoo; // okay


int foo(int x)
{
    return x;
}

int test()
{
    int (*fcnPtr)(int) = foo; // assign fcnPtr to function foo
    (*fcnPtr)(5); // call function foo(5) through fcnPtr.

   fcnPtr(5); // call function foo(5) through fcnPtr.
    return 0;
}
