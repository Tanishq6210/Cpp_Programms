#include<bits/stdc++.h>
#define MAX 3
using namespace std;

int arr[MAX];
int rear=-1, front=-1;



bool isFull(){
	return rear==MAX-1;
}

bool isEmpty(){
	if(front==rear)
		return true;
	else return false;
}

void enqueue(int data){
	if(isFull())
		cout<<"Can't enqueue since queue is full.\n";
	rear++;
	arr[rear] = data;
}

int dequeue(){
	if(isEmpty())
		cout<<"Queue is Empty cant dequeue...\n";
	front++;
	return arr[front];
}

void display(){
	for(int i=front+1; i<=rear; i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}

int main()
{
	do{
		int choice;
		cout<<"Enter the choice: \n1: enqueue\n2: dequeue\n3:display\n";
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
