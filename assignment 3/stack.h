/*
Name:- Atharva Kinikar
Div:- SE10
Batch:- F10
Roll.No:-23241
*/

#include<iostream>
using namespace std;

template<class T>
struct Node{ //structure node to store data and link to next pointer
    T data; 
    struct Node* link;
    
};

template<class T>
class stack{ //class stack which contains stack operation functions
    public:
    struct Node<T>* top=NULL; //top pointer to point to the head of linked list
    
    //stack operation functions
    public:
    void push(T data); 
    void pop();
    T peek();
    bool isempty(){ //isempty function to check if stack is empty
        return top==NULL;
    }
};


template<class T>
void stack<T>::push(T data) //push function
{
    struct Node<T>* temp;
    temp=new Node<T>();

    if(!temp)
    {
        cout<<"Heap overflow"<<endl; //checking for overflow condition
    }

    temp->data=data; //storing data in a new node

    temp->link=top; //storing link of next node in pointer

    top=temp; //making the temporary node as top
}


template<class T>
T stack<T>::peek() //peek function to access top element of the stack
{
    if(isempty()) //checking if stack is empty
    return -1;

    else
    return top->data;
}

template<class T>
void stack<T>::pop() //pop function to pop elemets from stack
{
    struct Node<T>* temp;
    temp=new Node<T>();

    if(top==NULL) //checking stack underflow condition
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
