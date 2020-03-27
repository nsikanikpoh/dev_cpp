#include <iostream>
#include <cassert>

class Stack
{
private:
	static constexpr int s_maxStackLength{ 10 };
	int m_array[s_maxStackLength]; // Here's where we're going to store our stack data
	int m_next = 0; // This will hold the index of the next free element on the stack

public:

	void reset()
	{
		m_next = 0;
	}

	bool push(int value)
	{
		// If the stack is already full, return false and bail
		if (m_next == s_maxStackLength)
			return false;

		m_array[m_next++] = value; // set the next free element to the value, then increase m_next
		return true;
	}

	int pop()
	{
		// If there are no elements on the stack, assert out
		assert (m_next > 0 && "Can not pop empty stack");

                // m_next points to the next free element, so the last valid element is m_next -1.
                // what we want to do is something like this:
                // int val = m_array[m_next-1]; // get the last valid element
                // --m_next; // m_next is now one less since we just removed the top element
                // return val; // return the element
                // that can be condensed down into this:
		return m_array[--m_next];
	}

	void print()
	{
		std::cout << "( ";
		for (int i{ 0 }; i < m_next; ++i)
			std::cout << m_array[i] << ' ';
		std::cout << ")\n";
	}
};

int main()
{
	Stack stack;

	stack.print();

	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();

	stack.pop();
	stack.print();

	stack.reset();
	stack.print();

	return 0;
}
