/*
Name:- Atharva Kinikar
Div :- SE10
Batch :- F10
Roll.No :- 23241
*/

#include<bits/stdc++.h>
using namespace std;

struct patient{
    string pat_name;
    string pat_disease;
    int pat_age;
    float pat_weight;
    
};

class Queue{
    public:
    int front,rear;
    int max;
    
    
    Queue(int n){
        max=n;
        front=-1;
        rear=-1;
    }

    void enqueue(struct patient pt[],string,string,int,float);
    void dequeue(struct patient pt[]);
    bool isempty();
    bool isfull();
    void display(struct patient pt[]);
};

void Queue::display(struct patient pt[])
{
    if(isempty())
    {
        cout<<"The queue is empty"<<endl;
    }
    
     else if(rear>=front)
    {
        cout<<"~~~~~~~The following patients are in the queue~~~~~~~~\n";
        for(int i=front;i<=rear;i++){
            cout<<"*************************************"<<endl;
            cout<<"Name of the patient => "<<pt[i].pat_name<<endl;
            cout<<"Age of the patient => "<<pt[i].pat_age<<endl;
            cout<<"Weight of the patient => "<<pt[i].pat_weight<<endl;
            cout<<"Disease => "<<pt[i].pat_disease<<endl;
        }
    }
    else
    {
        cout<<"~~~~~~~The following patients are in the queue~~~~~~~~\n";
        for(int i=front;i<max-1;i++){
            cout<<"*************************************"<<endl;
            cout<<"Name of the patient => "<<pt[i].pat_name<<endl;
            cout<<"Age of the patient => "<<pt[i].pat_age<<endl;
            cout<<"Weight of the patient => "<<pt[i].pat_weight<<endl;
            cout<<"Disease => "<<pt[i].pat_disease<<endl;
        }
        for(int i=0;i<front;i++)
        {
            cout<<"*************************************"<<endl;
            cout<<"Name of the patient => "<<pt[i].pat_name<<endl;
            cout<<"Age of the patient => "<<pt[i].pat_age<<endl;
            cout<<"Weight of the patient => "<<pt[i].pat_weight<<endl;
            cout<<"Disease => "<<pt[i].pat_disease<<endl;
        }
    }
}

bool Queue::isempty()
{
    if(front==-1)
    return true;
    else 
    return false;
}

bool Queue::isfull()
{
    if((front==0 && rear==max-1) || rear==front-1)
    return true;
    else 
    return false;
}

void Queue::enqueue(struct patient pt[],string name,string disease,int age,float weight)
{
    if(isfull()){
        cout<<"Queue is full cannot admit a patient"<<endl;
    }
    else{
        if(front==-1)
        {
            front=rear=0;
            pt[rear].pat_name=name;
            pt[rear].pat_age=age;
            pt[rear].pat_weight=weight;
            pt[rear].pat_disease=disease;
        }

        else if (rear == max-1 && front != 0)
        {
            rear=0;
            pt[rear].pat_name=name;
            pt[rear].pat_age=age;
            pt[rear].pat_weight=weight;
            pt[rear].pat_disease=disease;
        }

        else if (rear == max-1 && front != 0)
        {
            rear=0;
            pt[rear].pat_name=name;
            pt[rear].pat_age=age;
            pt[rear].pat_weight=weight;
            pt[rear].pat_disease=disease;
        }

        else{
            rear++;
            pt[rear].pat_name=name;
            pt[rear].pat_age=age;
            pt[rear].pat_weight=weight;
            pt[rear].pat_disease=disease;
        }
    }
}

void Queue::dequeue(struct patient pt[])
{
    string temp_name,temp_disease;
    int temp_age;
    float temp_weight;
    if(isempty())
    {
        cout<<"Queue is empty cannot remove a patient"<<endl;
    }
    else{
        temp_name=pt[front].pat_name;
        temp_disease=pt[front].pat_disease;
        temp_age=pt[front].pat_age;
        temp_weight=pt[front].pat_weight;
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else if(front==max-1)
        {
            front=0;
        }
        else 
        front++;
        cout<<"*********The following Patient has been admitted************\n";
        cout<<"Name of the patient => "<<temp_name<<endl;
        cout<<"Age of the patient => "<<temp_age<<endl;
        cout<<"Weight of the patient => "<<temp_weight<<endl;
        cout<<"Disease => "<<temp_disease<<endl;
    }
}



int main(){
    string name,disease,clr;
    int age,choice,n;
    float weight;
    
    cout<<"enter the maximum capacity of hospital => ";
        cin>>n;
      struct patient pt[n];
    Queue obj(n);
    do{
        cout<<"*************************************"<<endl;
        cout<<"Select the choice of operation to be performed :"<<endl;
        cout<<"1.Enqueue a patient\n2.Dequeue a patient\n3.Display the queue\n4.Exit\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
            getline(cin,clr);
            cout<<"enter the name of the patient => ";
            getline(cin,name);
            cout<<"enter the disease of the patient => ";
            getline(cin,disease);
            cout<<"enter the age of the patient => ";
            cin>>age;
            cout<<"enter the weight of the patient => ";
            cin>>weight;
            obj.enqueue(pt,name,disease,age,weight);
            break;

            case 2:
            obj.dequeue(pt);
            break;

            case 3:
            obj.display(pt);
            break;

            case 4:
            cout<<"Exiting the program"<<endl;
            break;

            default:
            cout<<"enter a valid choice"<<endl;
        }
    }while(choice!=4);
}