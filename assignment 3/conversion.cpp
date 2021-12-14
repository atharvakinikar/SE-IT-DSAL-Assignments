/*
Name:- Atharva Kinikar
Div:- SE10
Batch:- F10
Roll.No:-23241
*/

#include"stack.h" //included stack.h header file
#include<algorithm>
#include<string>

int prec(char c) {//prec function to check precedence of the operators
    if(c == '^')
        return 3;
    else if(c == '/' || c=='*')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void postfix(string s) //postfix function to convert infix to postfix
{
    stack<char>st; //declaring character type stack
    string result; 

    for(int i=0;i<s.length();i++)
    {
        char c=s[i]; 
        if((c>='a' && c<='z')||(c>='A' && c<='Z')||(c>='0'&&c<='9')) //checking if the character is an alphabet or number
        {
            result+=c;
        }

        else if(c=='(') //checking if character is '('
        st.push('(');

        else if(c==')') //checking if character is ')'
        {
            while(st.peek()!='(') //if ')' is found, adding it to output string
            {
                result+=st.peek();
                st.pop();
            }
            st.pop();
        }

        else{
                //if operator is found, adding the operator to the output string
                while(!st.isempty() && prec(s[i])<=prec(st.peek())){
                result+=st.peek();
                st.pop();
             }

            st.push(c);
        }
    }
    //popping out remaining elements
    while(!st.isempty()){
        result+=st.peek();
        st.pop();
    }

    cout<<"Converted Postfix Expression=> "<<result<<endl; //printing converted output expression
}

string postfix_for_prefix(string s) //special postfix function for prefix conversion method
{
    stack<char>st;
    string result;

    for(int i=0;i<s.length();i++)
    {
        char c=s[i];
        if((c>='a' && c<='z')||(c>='A' && c<='Z')||(c>='0'&&c<='9'))
        {
            result+=c;
        }

        else if(c=='(')
        st.push('(');

        else if(c==')')
        {
            while(st.peek()!='(')
            {
                result+=st.peek();
                st.pop();
            }
            st.pop();
        }

        else{
            if(c=='^'){
                while(!st.isempty() && prec(s[i])<=prec(st.peek())){
                result+=st.peek();
                st.pop();
            }
            }

            else{
                 while(!st.isempty() && prec(s[i])<prec(st.peek())){
                result+=st.peek();
                st.pop();
            }
            }
            st.push(c);
        }
    }

    while(!st.isempty()){
        result+=st.peek();
        st.pop();
    }

    return result;
}

string prefix(string s) //function to convert prefix expression
{
    reverse(s.begin(),s.end()); //reversing the string
    for(int i=0;i<s.length();i++) 
    {
        if(s[i]=='(')
        s[i]=')';
        else if(s[i]==')')
        s[i]='(';
    }

    string result=postfix_for_prefix(s); //converting the expression
    reverse(result.begin(),result.end()); //reversing the output string

    return result;
}

float operation(char o,float a, float b) //peration function to check if operator is present
{
	switch(o)
	{
	case '+': return a+b;break;
	case '-': return a-b;break;
	case '*': return a*b;break;
	case '/': return a/b;break;
	case '^': int i=0,p=1;while(i++<b) p=p*a; return p;
	}
	return 0;
}

void Evalpost(string str) //postfix evaluation function
{
	float o1,o2,r; 
	stack<int>s; //declaring int type stack
	for(int i=0;str[i]!='\0';i++)
	{
		if(str[i]>='0' &&str[i]<='9') //if digit is found, pushing it to the stack
			s.push(str[i]-48);
		else //adding to the expression
		{
			o2=s.peek();
            s.pop();
			o1=s.peek();
            s.pop();
			r=operation(str[i],o1,o2);
			s.push(r);
		}
	}
	cout<<"Postfix Evaluation Result=>"<<s.peek()<<endl; //printing the result 
}

void Evalpre(string str) //function to evaluate prefix
{
	float o1,o2,r;
	stack<int>s;
	for(int i=str.length()-1;i>-1;i--)
	{
		if(str[i]>='0' &&str[i]<='9') //if digit is found, pushing it to the stack
			s.push(str[i]-48);
		else //adding to the expression
		{
			o1=s.peek();
            s.pop();
			o2=s.peek();
            s.pop();
			r=operation(str[i],o1,o2);
			s.push(r);
		}
	}
	cout<<"Prefix Evaluation Result=>"<<s.peek()<<endl; //printing the result
}


int main()
{
    string str;
    int choice;
    do{
        cout<<"*************************************"<<endl;
        cout<<"Enter the operation to be performed\n1.Convert to Postfix Expression\n2.Convert to Prefix Expression\n3.Postfix Evaluation\n4.Prefix Evaluation\n5.Exit\n";
        cin>>choice;
        switch(choice)
        {

            case 1:
            cout<<"Enter the expression=>"<<endl;
            cin>>str;
            postfix(str);
            break;

            case 2:
            cout<<"Enter the expression=>"<<endl;
            cin>>str;
            cout<<"Converted Prefix Expression=> "<<prefix(str)<<endl;
            break;

            case 3:
            cout<<"Enter expression=>"<<endl;
            cin>>str;
            Evalpost(str);
            break;

            case 4:
            cout<<"Enter expression=>"<<endl;
            cin>>str;
            Evalpre(str);
            break;

            case 5:
            cout<<"Exiting the code"<<endl;
            cout<<"*************************************"<<endl;
            break;

            default:
            cout<<"Enter valid choice"<<endl;
            break;
        }
    }while(choice!=5);
}