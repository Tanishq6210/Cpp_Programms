#include<bits/stdc++.h>
#define MAX 30
using namespace std;

int front=-1,rear=-1;
int arr[MAX];
int c;

int dequeue();
void enqueue(int data);

bool isEmpty(){
	if(front==rear)
		return true;
	else if(front==rear==-1)
		return true;
	else return false;
}

bool isFull(){
	return rear==MAX-1;
}

void re_enqueue(int data){
	rear++;
	arr[rear]=data;
}
void enqueue(int data){
	if(isFull()) {
		cout<<"Cant push element.\n";	
		return; 
	}
	c=rear-front;
	rear++;
	arr[rear]=data;
	for(int i=0; i<c; i++){
		int x = dequeue();
		re_enqueue(x);
	}
}

int dequeue(){
	front++;
	return arr[front];
}

void display(){
	for(int i=rear; i>front; i--){
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}
int main()
{
	do
	{
		int choice;
		cout<<"Enter the choice: \n1: enqueue\n2: dequeue\n3: display\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
				int data;
				cout<<"Enter data: ";
				cin>>data;
				enqueue(data);
				cout<<"\n";
				break;
			case 2:
				cout<<"The popped element is: "<<dequeue()<<"\n";
				break;
			case 3:
				display();
				break;
			default:
				exit(0);
		}
	}while(true);
	return 0;
}
