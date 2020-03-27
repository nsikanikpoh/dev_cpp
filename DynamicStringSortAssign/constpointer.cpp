int value1 = 5;
int value2 = 6;

int * const ptr = &value1; // okay, the const pointer is initialized to the address of value1
ptr = &value2; // not okay, once initialized, a const pointer can not be changed.
//However, because the value being pointed to is still non-const, it is possible to change the value being pointed
//to via dereferencing the const pointer:


int value = 5;
int *const ptr = &value; // ptr will always point to value
*ptr = 6; // allowed, since ptr points to a non-const int
//Const pointer to a const value

//Finally, it is possible to declare a const pointer to a const value by using the const keyword both before the type and
// before the variable name:

int value = 5;
const int *const ptr = &value;
//A const pointer to a const value can not be set to point to another address, nor can the value it is pointing to be
//changed through the pointer.

//A non-const pointer can be redirected to point to other addresses.
//A const pointer always points to the same address, and this address can not be changed.
//A pointer to a non-const value can change the value it is pointing to. These can not point to a const value.
//A pointer to a const value treats the value as const (even if it is not), and thus can not change the value it is pointing to.
//Keeping the declaration syntax straight can be challenging. Just remember that the type of value the pointer points to is always on the far left:


int value = 5;
const int *ptr1 = &value; // ptr1 points to a "const int", so this is a pointer to a const value.
int *const ptr2 = &value; // ptr2 points to an "int", so this is a const pointer to a non-const value.
const int *const ptr3 = &value; // ptr3 points to a "const int", so this is a const pointer to a const value.
