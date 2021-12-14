#include "tree.h"

class ThreadedBinaryTree
{
    N *root; //Temporary node
public:
    ThreadedBinaryTree() //Temporary node initialization
    {
        root = new N(65739);
        root->l = root->r = root;
        root->rt = 1; //child
        root->lt = 0; //threaded connection
    }
    void create();
    void insert(int data);
    N *inordsuc(N *);
    void inorder();
    N *preordsuc(N *c);
    void preorder();
};
void ThreadedBinaryTree::preorder()
{
    N *c = root->l;
    while (c != root)
    {
        cout << " " << c->data;
        c = preordsuc(c);
    }
}
N *ThreadedBinaryTree::preordsuc(N *c)
{
    if (c->lt == 1)
    {
        return c->l;
    }
    while (c->rt == 0)
    {
        c = c->r;
    }
    return c->r;
}
void ThreadedBinaryTree::inorder()
{
    N *c = root->l;
    while (c->lt == 1)
        c = c->l;
    while (c != root)
    {
        cout << " " << c->data;
        c = inordsuc(c);
    }
}
N *ThreadedBinaryTree::inordsuc(N *c)
{
    if (c->rt == 0)
        return c->r;
    else
        c = c->r;
    while (c->lt == 1)
    {
        c = c->l;
    }
    return c;
}
void ThreadedBinaryTree::create()
{
    int n;
    cout << "\nHow many no. of nodes do you want to insert: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int info;
        cout << "\nPlease enter the data to be inserted: ";
        cin >> info;
        insert(info);
    }
}
void ThreadedBinaryTree::insert(int data)
{
    if (root->l == root && root->r == root) //when there is no node
    {
        N *p = new N(data);
        p->l = root->l;
        p->lt = root->lt; //0
        p->rt = 0;
        p->r = root->r;
        root->l = p;
        root->lt = 1;
        cout << "\nInsertion started successfully.\n Data inserted is:" << data << endl;
        return;
    }
    N *curr;        //new node;
    curr = root->l; //first node inserted in the tree
    while (1)
    {
        int ch;
        cout << "Press 1:Insert on left \nPress 2:Insert on right\nEnter your choice : " << endl;

        cin >>
            ch;
        if (ch == 2) //For insertion on right
        {
            if (curr->rt == 0)
            {
                N *p = new N(data);
                p->r = curr->r;
                p->l = curr;
                p->rt = p->lt = 0;
                curr->r = p;
                curr->rt = 1;
                cout << data << " is inserted on the right successfully. " << endl;
                return;
            }
            else
                curr = curr->r;
        }
        if (ch == 1) //For insertion on left
        {
            if (curr->lt == 0)
            {
                N *p = new N(data);
                p->l = curr->l;
                p->r = curr;
                p->lt = p->rt = 0;
                curr->l = p;
                curr->lt = 1;
                cout << data << " is inserted on the left successfully. " << endl;
                return;
            }
            else
                curr = curr->l;
        }
    }
}