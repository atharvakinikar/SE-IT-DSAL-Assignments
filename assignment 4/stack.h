#include<iostream>
using namespace std;

template<class T>
struct Node{
    T data;
    struct Node* link;
    
};

template<class T>
class stack{
    public:
    struct Node<T>* top=NULL;
    
    public:
    void push(T data);
    void pop();
    T peek();
    bool isempty(){
        return top==NULL;
    }
};


template<class T>
void stack<T>::push(T data)
{
    struct Node<T>* temp;
    temp=new Node<T>();

    if(!temp)
    {
        cout<<"Heap overflow"<<endl;
    }

    temp->data=data;

    temp->link=top;

    top=temp;
}


template<class T>
T stack<T>::peek()
{
    // if(isempty())
    // return;

    
    return top->data;
}

template<class T>
void stack<T>::pop()
{
    struct Node<T>* temp;
    temp=new Node<T>();

    if(top==NULL)
    {
        cout<<"Stack underflow"<<endl;
    }
    else
    {
        temp=top;
        top=top->link;
        temp->link=NULL;
        free(temp);
    }
}
