/*Name:- Atharva Kinikar
Roll.No:- 23241
Div:- SE10
Batch:- F10
Assigment-1
*/
#include<iostream>
#include<string.h>
using namespace std;

struct stud//structure stud 
{
    string name;//variable name
    int roll;//variable roll number
    float sgpa;//variable sgpa
};

class student{ //creating a class student
    public:
    int count;//count variable to keep track of current total students
    struct stud st[15];//array of structure stud

    public:
    student(int c){//parameterised constructor
        count=c;
        cout<<"Number of Students => "<<count<<endl;//printing number of students 
    }
    //declaring member functions of the class student
    void read_data();
    void display();
    void insert_record();
    void search_sgpa();
    void sort_rollno();
    int getcount();
    void qsort(int,int);
    int partition(int,int);
    void insertionSort();
    void name_search(int,int);
    void display_reverse();
};

void student::read_data()//defining function read_data outside the class
{
    string emp;//declaring empty string to avoid \n
    for(int i=0;i<count;i++)
    {
    cout<<"enter roll no -> ";
    cin>>st[i].roll;//taking input for roll number
    cout<<"enter sgpa -> ";
    cin>>st[i].sgpa;//taking inpu for sgpa
    getline(cin,emp);
    cout<<"enter the name of student -> ";
    getline(cin,st[i].name);//taking input for name
    }
    cout<<"***********************************************************"<<endl;
}

void student::display()//defining function display outside the class
{
    cout<<"***********************************************************"<<endl;
    cout<<endl;
    cout<<"Name"<<"\t\t\t"<<"Roll.No"<<"\t\t\t"<<"SGPA"<<endl;
    for(int i=0;i<count;i++)
    {
        cout<<st[i].name<<"\t\t\t";//printing name of student
        cout<<st[i].roll<<"\t\t\t";//printing roll no. of student
        cout<<st[i].sgpa<<endl;//printing sgpa of student
    }

    cout<<"***********************************************************"<<endl;
}

void student::display_reverse()//defining function display_reverse outside the class
{
    cout<<"***********************************************************"<<endl;
    cout<<endl;
    cout<<"Name"<<"\t\t\t"<<"Roll.No"<<"\t\t\t"<<"SGPA"<<endl;
    for(int i=count-1;i>=0;i--)
    {
        cout<<st[i].name<<"\t\t\t";//printing name of student
        cout<<st[i].roll<<"\t\t\t";//printing roll no. of student
        cout<<st[i].sgpa<<endl;//printing sgpa of student
    }
    cout<<"***********************************************************"<<endl;
}

void student::insert_record()//defining function insert_record outside the class
{
    string emp;
    getline(cin,emp);
    cout<<"Enter the name of the student =>";
    getline(cin,st[count].name);//taking input for name
    cout<<"Enter the roll number of student => ";
    cin>>st[count].roll;//taking input for roll number
    cout<<"Enter SGPA => ";
    cin>>st[count].sgpa;//taking input for sgpa
    count++;
    cout<<"***********************************************************"<<endl;
}

void student::search_sgpa()//defining function search_sgpa outside the class
{
    float find,flag=0;
    cout<<"enter sgpa to be found"<<endl;
    cin>>find;//taking inout for sgpa to be found
    for(int i=0;i<count;i++)
    {
        if(st[i].sgpa==find)//checking the sgpa in the array of structure stud
        {
            flag=1;
           cout<<st[i].name<<"\t\t"<<st[i].roll<<"\t\t"<<st[i].sgpa<<endl;//printing the details of the student corresponding to given sgpa
        }
    }

    if(flag==0)
    cout<<"No matching SGPA found"<<endl;//if sgpa is not found
    cout<<"***********************************************************"<<endl;
}

int student::getcount(){
    return count;//returning current count of students entered
}

//bubble sort to sort roll numbers
void student::sort_rollno(){
    struct stud temp;//declaring temporary structure for swapping
    for(int i=0;i<count;i++)
    {
        for(int j=0;j<count-i-1;j++)
        {
            if(st[j].roll>st[j+1].roll)
            {
                //swapping the data at two indices when condition is satisfied
                temp=st[j+1];
                st[j+1]=st[j];
                st[j]=temp;
            }
        }
    }
    display();//display the sorted record
}

int student::partition(int l,int r)//defining function partition outside the class
{
    int pivot=st[r].sgpa;//taking pivot as last element
    int i=(l-1);
    struct stud temp;//declaring temporary structure for swapping
    for(int j=l;j<=r-1;j++)
    {
        if((st[j].sgpa)<(pivot))
        {
            i++;//incrementing lower pointer
            //swapping the records if condition is satisfied
            temp=st[i];
            st[i]=st[j];
            st[j]=temp;
        }
    }
    //swapping the pivot element with the first element greater than the pivot element to return partition index
    temp=st[r];
    st[r]=st[i+1];
    st[i+1]=temp;
    return(i+1);//returning partition index
}

void student::qsort(int l,int r)//defining function qsort outside the class
{
if(l<r)
{
    int pindex=partition(l,r);//calling partition function
    qsort(l,pindex-1);//recursive call to qsort function
    qsort(pindex+1,r);//recursive call to qsort function
}
}

void student::insertionSort()//defining function insertionsort outside the class
{
    int i,j;
    struct stud key;
    for (i = 1; i < count; i++)
    {
        key = st[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && ((st[j].name).compare(key.name)> 0))
        {
            st[j+1] = st[j];
            j = j - 1;
        }
        st[j+1] = key;//inserting the current element at apporpriate position
    }
    display();//displaying sorted record
}

void student::name_search(int l,int r)//defining function namesearch outside the class
{
    string str;
    bool check=0;
    cout<<"enter the name to be found => ";
    cin>>str;//taking input for name to be found
    while(l<=r)
    {
        int mid=(r+l)/2;

        if((st[mid].name).compare(str)==0)
        {
            //if given name is at mid printing the found element
            cout<<st[mid].name<<"\t\t"<<st[mid].roll<<"\t\t"<<st[mid].sgpa<<endl;
            check=1;
            break;   
        }
        else if((st[mid].name).compare(str)<0)
        {
            //if given name is is larger than middle then changing lower bound
            l=mid+1;
        }
        else{
            //if given name is is smaller than middle then changing upper bound
            r=mid-1;
        }

        
    }
    if(check==0)
        cout<<"Record Not Found"<<endl;//if record not found
    cout<<"***********************************************************"<<endl;
}


int main()
{
    int n;
    cout<<"enter number of students : ";
    cin>>n;//taking input for number of entries
    student obj(n);//object creating
    int choice;
    
    do{
        //taking input from user for operation to be performed
        cout<<"Enter the choice number task to be performed"<<endl;
    cout<<"1.Read Data\n2.Display Data\n3.Insert Data\n4.Search SGPA\n5.Sort Data by Roll Number\n6.Arrange Students Alphabetically by name\n7.Obtain Merit List\n8.Search a student by name\n9.Exit\n";
    cout<<"***********************************************************"<<endl;
    cin>>choice;

    switch(choice)
    {
        case 1:
        obj.read_data();
        break;

        case 2:
        obj.display();
        break;

        case 3:
        obj.insert_record();
        break;

        case 4:
        obj.search_sgpa();
        break;

        case 5:
        obj.sort_rollno();
        break;

        case 6:
        obj.insertionSort();
        break;

        case 7:
        obj.qsort(0,obj.count-1);
        obj.display_reverse();
        break;

        case 8:
        obj.name_search(0,obj.count-1);
        break;

        case 9:
        cout<<"Exiting the program"<<endl;
        break;

        default:
        cout<<"Invalid choice"<<endl;
    }
    }while(choice!=9);
   
}