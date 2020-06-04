#include <iostream>

using namespace std;


class StringNode   // a node in a list of strings
{
private:
    string elem; // element value
    StringNode* next; // next item in the list
    friend class StringLinkedList; // provide StringLinkedList access
};


class StringLinkedList   // a linked list of strings
{
public:
    StringLinkedList();//empty list constructor
    ~StringLinkedList();//destructor
    bool empty() const;//is list empty?
    const string& front() const;//get front element
    void addFront(const string& e);//add to front of list
    void removeFront();//remove front item list
private:
    StringNode* head;// pointer to the head of list
};


StringLinkedList::StringLinkedList()
    : head(NULL) { } // constructor
StringLinkedList::~StringLinkedList()
{
    while(!empty())
        removeFront();    // destructor
}

bool StringLinkedList::empty() const
{
    return head == NULL;    // is list empty?
}

const string& StringLinkedList::front() const
{
    return head->elem;    // get front element
}

void StringLinkedList::addFront(const string& e)   // add to front of list
{
    StringNode* v = new StringNode;
// create new node
    v->elem = e;
// store data
    v->next = head;
// head now follows v
    head = v;
// v is now the head
}

void StringLinkedList::removeFront()  //remove front item
{
    StringNode* old = head;//save current head
    head = old->next;//skip over old head
    delete old;//delete the old head
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
