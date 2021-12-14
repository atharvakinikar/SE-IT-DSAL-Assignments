#include <iostream>
using namespace std;
class ThreadedBinaryTree;
class N
{
    N *l, *r;
    int data;
    bool rt, lt;

public:
    N()
    {
        data = 0;
        l = NULL;
        r = NULL;
        rt = lt = 0;
    }
    N(int d)
    {
        l = NULL;
        r = NULL;
        rt = lt = 0;
        data = d;
    }
    friend class ThreadedBinaryTree;
};