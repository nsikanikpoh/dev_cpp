
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
void printList(Node* head)
{


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

// Reverses the given linked list by changing its .next pointers and
// its head pointer. Takes a pointer (reference) to the head pointer
void reverse(Node** head)
{
    Node* prev = NULL;       // the prev pointer
    Node* current = *head;   // the main pointer

    // traverse the list
    while (current != NULL)
    {
        // tricky: note the next node
        struct Node* next = current->next;

        current->next = prev;  // fix the current node

        // advance the two pointers
        prev = current;
        current = next;
    }

    // fix the head pointer to point to the new front
    *head = prev;
}

// reverse linked list iteratively
int main(void)
{
    // input keys
    int keys[] = { 1, 2, 3, 4, 5, 6 };
    int n = sizeof(keys)/sizeof(keys[0]);

    struct Node *head = NULL;
    for (int i = n - 1; i >=0; i--)
        push(&head, keys[i]);

    reverse(&head);

    printList(head);

    return 0;
}
