#include<iostream>
#define max 60
using namespace std;
struct student
{
    string regno;
    int age;
    float cgpa;
};

 

struct student a[max];
int top=-1;

 
int isfull()
{
    if(top==max)
      return 1;
    else
      return 0;
}

void push(struct student s)
{
  top++;
  if(isfull())
  {cout<<"stack is full cant push....";
    return;
  }
  a[top]=s;
}

void pop()
{
    if(top==-1)
    {
        cout<<"stack is empty. Can't pop....";
        return;
    }
    struct student temp=a[top];
    cout<<"the popped element is "<<temp.regno<<" ";
    cout<<" "<<temp.age<<" "<<temp.cgpa<<"\n";
    top--;
}

void display()
{
    int i;
    for(i=0;i<=top;i++)
       cout<<a[i].regno<<" "<<a[i].age<<" "<<a[i].cgpa<<" ";
}


int main()
{
    int choice;
    struct student ss;
    do
    {
    
    cout<<"enter ur choice 1-push 2-pop 3-display .......";
    cin>>choice;
    switch(choice)
    {
        case 1: cout<<"enter the regno,age and cgpa of the student u want to insert";
                cin>>ss.regno>>ss.age>>ss.cgpa;
                push(ss);
                break;
        case 2: pop();
                break;
        case 3: display();
                break;
        default: exit(0);
        
    }
  }while(choice!=4);
}
