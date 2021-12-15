//============================================================================
// Name        : DSAL.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================




#include <iostream>
using namespace std;
# define Max 10

struct admission{
	int roll;
	string name;
	float fees;
};

class CircQueue{
	int rear, front;
	int Size;
	admission array[10];
public:
	CircQueue(int);
	void enQueue();
	void deQueue();
	int isFull();
	int isEmpty();
	void Display();
};

CircQueue::CircQueue(int size){
	Size = size;
	front = rear = -1;
}

int CircQueue::isFull(){
	if((front == rear + 1) || (front == 0 && rear == Size - 1)){
		return 1;
	}
	return 0;
}

int CircQueue::isEmpty(){
	if (front==-1){
		return 1;
	}
	return 0;
}

void CircQueue::enQueue(){
	if (isFull()){
		cout<<"Queue full (Overflow)";
	}else{
		if (front == -1){
			front = 0;
		}
		int roll;
		string name;
		float fees;
		cout<<"Enter the roll of student :"<<endl;;
		cin>>roll;
		cout<<"Enter the name of student :"<<endl;;
		cin>>name;
		cout<<"Enter the fees of student :"<<endl;;
		cin>>fees;
		rear = (rear+ 1) % Size;
		array[rear].roll=roll;
		array[rear].name=name;
		array[rear].fees=fees;
	}
}

void CircQueue::deQueue(){
	admission ele;
	if (isEmpty()){
		cout<<"The Queue is empty (Underflow)"<<endl;
		exit(0);
	}
	ele = array[front];
	if (front == rear){
		front = -1;
		rear = -1;
	}else{
		front = (front + 1) % Size;
	}
	cout<<"Popping out the value: "<<endl;
	cout<<"Roll: "<<ele.roll<<endl;
	cout<<"Name: "<<ele.name<<endl;
	cout<<"Fees: "<<ele.fees<<endl;
}

void CircQueue::Display(){
	int i;
	if (isEmpty()){
		cout<<"Queue is empty (Underflow)"<<endl;
	}else{
		cout<<"The circular queue is :"<<endl<<endl;
		for (i = front; i != rear ; i = (i+1)%Size){
			cout<<"Roll: "<<array[i].roll<<endl;
			cout<<"Name: "<<array[i].name<<endl;
			cout<<"Fees: "<<array[i].fees<<endl;
		}
		cout<<endl;
		cout<<"Roll: "<<array[i].roll<<endl;
		cout<<"Name: "<<array[i].name<<endl;
		cout<<"Fees: "<<array[i].fees<<endl;
	}
}

int main() {
	CircQueue obj(7);
	int choice;
	cout<<"\n\t Queue operations are:";
	cout<<"\n\t1.EnQueue\n\t2.DeQueue\n\t3.Display\n\t4.Exit";
	do{
		cout<<"\nEnter your choice: ";
		cin>>choice;
		switch(choice){
		case 1:
			{
				obj.enQueue();
				break;
			}
		case 2:
			{
				obj.deQueue();
				break;
			}
		case 3:
			{
				obj.Display();
				break;
			}
		case 4:
			{
				cout<<"Exiting the code";
				exit(0);
			}
		default:
			{
				cout<<"Enter a valid choice";
			}
		}
	}while(choice != 4);
	return 0;
}
