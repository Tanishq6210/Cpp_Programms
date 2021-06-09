#include<process.h>
#include<iostream>
#define SIZE 5
using namespace std;
/****    Program to Implement Circular Queue using Array    ****/

 

void insert();
void delet();
void display();
int queue[SIZE], rear=-1, front=-1, item; 
main()
{
int ch; 
do
{ 
cout<<"\n1.\tInsert\n2.\tDeleten\n3.\tDisplay\n4.\tExit\n";
cout<<"Enter your choice: ";
cin>>ch;
switch(ch)
{
case 1:
insert();
break;
case 2:
delet();
break;
case 3:
display();
break;
case 4:
exit(0);  
default:       
cout<<"\n\nInvalid choice. Pleasr try again...\n";
}
} while(1);
}

 

void insert()
{
if((front==0 && rear==SIZE-1) || (front==rear+1))
cout<<"\nQueue is full.";
else
{
cout<<"\nEnter ITEM: ";
cin>>item;
if(rear == -1)
{
rear = 0;
front = 0;
}
else if(rear == SIZE-1) 
rear = 0;
else
rear++;
queue[rear] = item;
cout<<"\nItem inserted:"<< item<<"\n";
}                                       
}
void delet()
{
if(front == -1)
cout<<"Queue is empty.\n";
else
{
item = queue[front];
if(front == rear)
{
front = -1;
rear = -1;
}
else if(front == SIZE-1)
front = 0;
else
front++;

cout<<"\nITEM deleted:"<<item;
}                  
}


void  display()
{
int i;

 

 if(front<=rear)
     {if(front!=-1 && rear!=-1)
     for( i=front;i<=rear;i++)
      
       cout<<queue[i];
     }  
     else
     {
         for( i=front;i<=SIZE-1;i++)
           cout<<queue[i];
         for( i=0;i<=rear;i++)
           cout<<queue[i];
     }
}
