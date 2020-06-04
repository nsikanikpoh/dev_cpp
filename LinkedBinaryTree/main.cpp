#include <iostream>
#include <list>

using namespace std;


// base element type
typedef int Elem;
class LinkedBinaryTree
{
protected:
// insert Node declaration here. . .
    struct Node
    {
// a node of the tree
        Elem elt;
// element value
        Node* par;
// parent
        Node* left;
// left child
        Node* right;
// right child
        Node() : elt(), par(NULL), left(NULL), right(NULL) { } // constructor
    };

public:
// insert Position declaration here. . .
    class Position
    {
// position in the tree
    private:
// pointer to the node
        Node* v;
    public:
        Position(Node* _v = NULL) : v( _v) { }
// constructor
        Elem& operator*()
// get element
        {
            return v->elt;
        }
        Position left() const
// get left child
        {
            return Position(v->left);
        }
        Position right() const
// get right child
        {
            return Position(v->right);
        }
        Position parent() const
// get parent
        {
            return Position(v->par);
        }
        bool isRoot() const
// root of the tree?
        {
            return v->par == NULL;
        }
        bool isExternal() const
// an external node?
        {
            return v->left == NULL && v->right == NULL;
        }
        friend class LinkedBinaryTree;
// give tree access
    };
    typedef std::list<Position> PositionList;
// list of positions



public:
    LinkedBinaryTree();
// constructor
    int size() const;
// number of nodes
    bool empty() const;
// is tree empty?
    Position root() const;
// get the root
    PositionList positions() const;
// list of nodes
    void addRoot();
// add root to empty tree
    void expandExternal(const Position& p);
// expand external node
    Position removeAboveExternal(const Position& p); // remove p and parent
// housekeeping functions omitted. . .
protected:
// local utilities
    void preorder(Node* v, PositionList& pl) const; // preorder utility
private:
// pointer to the root
    Node* _root;
    int n;
// number of nodes
};

LinkedBinaryTree::LinkedBinaryTree()// constructor
    : _root(NULL), n(0) { }
int LinkedBinaryTree::size() const// number of nodes
{
    return n;
}
bool LinkedBinaryTree::empty() const// is tree empty?
{
    return size() == 0;
}
LinkedBinaryTree::Position LinkedBinaryTree::root() const // get the root
{
    return Position(_root);
}
void LinkedBinaryTree::addRoot()// add root to empty tree
{
    _root = new Node;
    n = 1;
}


// expand external node
void LinkedBinaryTree::expandExternal(const Position& p)
{
    Node* v = p.v;
// p’s node
    v->left = new Node;
// add a new left child
    v->left->par = v;
// v is its parent
    v->right = new Node;
// and a new right child
    v->right->par = v;
// v is its parent
    n += 2;
// two more nodes
}




LinkedBinaryTree::Position
// remove p and parent
LinkedBinaryTree::removeAboveExternal(const Position& p)
{
    Node* w = p.v;
    Node* v = w->par;
// get p’s node and parent
    Node* sib = (w == v->left ? v->right : v->left);
// child of root?
    if (v == _root)
    {
        _root = sib;
// . . .make sibling root
        sib->par = NULL;
    }
    else
    {
        Node* gpar = v->par;
// w’s grandparent
        if (v == gpar->left)
            gpar->left = sib;
// replace parent by sib
        else
            gpar->right = sib;
        sib->par = gpar;
    }
    delete w;
    delete v;
// delete removed nodes
    n -= 2;
// two fewer nodes
    return Position(sib);
}


// list of all nodes
LinkedBinaryTree::PositionList LinkedBinaryTree::positions() const
{
    PositionList pl;
// preorder traversal
    preorder(_root, pl);
    return PositionList(pl);
// return resulting list
}

// preorder traversal
void LinkedBinaryTree::preorder(Node* v, PositionList& pl) const
{
    pl.push_back(Position(v));// add this node
    if (v->left != NULL)
        preorder(v->left, pl);// traverse left subtree
    if (v->right != NULL)
        preorder(v->right, pl);// traverse right subtree
}


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
