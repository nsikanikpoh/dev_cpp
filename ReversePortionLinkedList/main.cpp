#include <iostream>
#include <string>
using namespace std;

// Data Structure to store a linked list node
struct Node
{
    int data;
    Node* next;
};

// Utility function to print a linked list
void printList(string msg, Node* head)
{
    cout << msg;

    Node* ptr = head;
    while (ptr)
    {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }

    cout << "NULL" << endl;
}

// Helper function to insert new Node in the beginning of the linked list
void push(Node** head, int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Iteratively reverse a linked list from position m to n
// Note that the head is passed by reference
void reverse(Node* &head, int m, int n)
{
    Node* prev = NULL;      // the prev pointer
    Node* curr = head;      // the main pointer

    // 1. Skip the first m nodes
    for (int i = 1; curr != NULL && i < m; i++)
    {
        prev = curr;
        curr = curr->next;
    }

    // prev now points to position the (m-1)'th node
    // curr now points to position the m'th node

    Node* start = curr;
    Node* end = NULL;

    // 2. Traverse and reverse the sub-list from position m to n
    for (int i = 1; curr != NULL && i <= n - m + 1; i++)
    {
        // Take note of the next node
        Node* next = curr->next;

        // move the 'curr' node onto the 'end'
        curr->next = end;
        end = curr;

        // move to the next node
        curr = next;
    }

    // start points to the m'th node
    // end now points to the n'th node
    // curr now points to the (n+1)'th node

    // 3. Fix the pointers and return the head node
    start->next = curr;
    if (prev != NULL)
    {
        prev->next = end;
    }
    // when m = 1 (prev is NULL)
    else
    {
        // fix the head pointer to point to the new front
        head = end;
    }
}

int main()
{
    int m = 2, n = 5;

    Node* head = NULL;
    for (int i = 7; i >= 1; i--)
        push(&head, i);

    printList("Original Linked List: ", head);
    reverse(head, m, n);
    printList("Reversed Linked List: ", head);

    return 0;
}
