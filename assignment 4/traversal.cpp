#include <iostream>
using namespace std;
#include "tree_header.h"
//#include "conversion_header.h"
#include "stack.h"
// #include "stack_imple.cpp"

expTree::expTree() //constructor
{
    root = NULL;
} //postfix expression

void expTree::createTree(string exp) //creation of expression tree
{
    int i = 0;
    treenode *temp;
    stack<treenode *> expTrStk; //stack having ->address as data of treenode type
    while (exp[i] != '\0')
    {
        temp = getTreeNode(exp[i]);
        if (!isOpera(exp[i])) //operand
        {
            expTrStk.push(temp);
            // cout<<"Operand data"<<temp->data;
        }
        else //operator
        {
            //temp=getTreeNode(exp[i]);
            temp->rchild = expTrStk.peek();
            expTrStk.pop();
            temp->lchild = expTrStk.peek();
            expTrStk.pop();
            expTrStk.push(temp);
            // cout<<"Operator data"<<temp->data;
        }
        i++;
    }
    root = expTrStk.peek();
    expTrStk.pop();
}
bool expTree::isOpera(char op)
{
    if (op == '+' || op == '-' || op == '*' || op == '/' || op == '%' || op == '^')
    {
        return true;
    }
    return false;
}

treenode *expTree::getTreeNode(char d)
{
    treenode *T;
    T = new treenode();
    T->data = d;
    T->lchild = NULL;
    T->rchild = NULL;
    return T;
}

treenode *expTree::getroot()
{
    return root;
}

void expTree::RInorderTraversal(treenode *T)
{
    if (T != NULL)
    {
        RInorderTraversal(T->lchild);
        cout << T->data << " ";
        RInorderTraversal(T->rchild);
    }
}

void expTree::RPreorderTraversal(treenode *T)
{
    if (T != NULL)
    {
        cout << T->data << " ";
        RPreorderTraversal(T->lchild);
        RPreorderTraversal(T->rchild);
    }
}

void expTree::RPostorderTraversal(treenode *T)
{
    if (T != NULL)
    {
        RPostorderTraversal(T->lchild);
        RPostorderTraversal(T->rchild);
        cout << T->data << " ";
    }
}

void expTree::NRInorderTraversal(treenode *T)
{
    stack<treenode *> s;
    treenode *curr = root;

    while (curr != NULL || s.isempty() == false)
    {
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->lchild;
        }
        curr = s.peek();
        s.pop();
        cout << curr->data << " ";
        curr = curr->rchild;
    }
}

void expTree::NRPreorderTraversal(treenode *T)
{
    if (root == NULL)
        return;

    stack<treenode *> s;
    treenode *curr = root;

    while (!s.isempty() || curr != NULL)
    {
        while (curr != NULL)
        {
            cout << curr->data << " ";

            if (curr->rchild)
                s.push(curr->rchild);

            curr = curr->lchild;
        }

        if (s.isempty() == false)
        {
            curr = s.peek();
            s.pop();
        }
    }
}

void expTree::NRPostorderTraversal(treenode *T)
{
    if (root == NULL)
        return;

    stack<treenode *> s1, s2;

    s1.push(root);
    treenode *curr;

    while (!s1.isempty())
    {
        curr = s1.peek();
        s1.pop();
        s2.push(curr);

        if (curr->lchild)
            s1.push(curr->lchild);
        if (curr->rchild)
            s1.push(curr->rchild);
    }

    while (!s2.isempty())
    {
        curr = s2.peek();
        s2.pop();
        cout << curr->data << " ";
    }
}

int main()
{
    int choice;
    string s;
    cout << "Enter the postfix expression" << endl;
    cin >> s;
    expTree obj;
    obj.createTree(s);
    do
    {
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "Enter the choice of operation to be perfromed\n1.Recursive Inorder Traversal\n2.Recursive Preorder Traversal\n3.Recursive Postorder Traversal\n4.Non-Recursive Inorder Traversal\n5.Non-Recursive Preorder Travseral\n6.Non-Recursive Postorder Traversal\n7.Exit\n";
        cin >> choice;
        switch (choice)
        {

        case 1:
            obj.RInorderTraversal(obj.getroot());
            break;

        case 2:
            obj.RPreorderTraversal(obj.getroot());
            break;

        case 3:
            obj.RPostorderTraversal(obj.getroot());
            break;

        case 4:
            obj.NRInorderTraversal(obj.getroot());
            break;

        case 5:
            obj.NRPreorderTraversal(obj.getroot());
            break;

        case 6:
            obj.NRPostorderTraversal(obj.getroot());
            break;

        case 7:
            cout << "Exiting the code";
            break;

        default:
            cout << "Enter valid operation\n";
        }
    } while (choice != 7);
}