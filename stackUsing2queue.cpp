#include<bits/stdc++.h>
#define MAX 30
using namespace std;

int que_one[MAX];
int front_one=-1,rear_one=-1;
int que_two[MAX];
int front_two=-1,rear_two=-1;
int c_one;
int c_two;

int dequeue_q1();
void enqueue_q1(int data);

bool isEmpty_q1(){
	if(front_one==rear_one)
		return true;
	else if(front_one==rear_one==-1)
		return true;
	else return false;
}

bool isEmpty_q2(){
	if(front_two==rear_two)
		return true;
	else if(front_two==rear_two==-1)
		return true;
	else return false;
}

bool isFull_q1(){
	return rear_one==MAX-1;
}

bool isFull_q2(){
	return rear_two==MAX-1;
}

void enqueue_q1(int data){
	if(isFull_q1()) {
		cout<<"Cant push element.\n";	
		return; 
	}
	rear_one++;
	que_one[rear_one]=data;
}

void enqueue_q2(int data){
	if(isFull_q2()) {
		cout<<"Cant push element.\n";	
		return; 
	}
	rear_two++;
	que_two[rear_two]=data;
}

int dequeue_q1(){
	front_one++;
	return que_one[front_one];
}

int dequeue_q2(){
	front_two++;
	return que_two[front_two];
}

void enqueue(int data){
	if(isEmpty_q1() && isEmpty_q2()){
		rear_two++;
		que_two[rear_two] = data;
	}else if(!isEmpty_q1()){
		rear_one++;
		que_one[rear_one] = data;
	}else if(!isEmpty_q2()){
		rear_two++;
		que_two[rear_two] = data;
	}
}

int dequeue(){
	if(isEmpty_q1() && isEmpty_q2()){
	cout<<"Stack Underflow...";
	return 0;
	}
	else if(!isEmpty_q1()){
		c_one = rear_one - front_one;
		for(int i=0; i<c_one-1; i++){
			int x = dequeue_q1();
			enqueue_q2(x);
		}
		return dequeue_q1();
	}else{
		c_two = rear_two - front_two;
		for(int i=0; i<c_two-1; i++){
			int x = dequeue_q2();
			enqueue_q1(x);
		}
		return dequeue_q2();
	}
}

void display(){
	if(!isEmpty_q1()){
		for(int i=front_one+1; i<=rear_one; i++){
			cout<<que_one[i]<<" ";
		}
		cout<<"\n";
	}else if(!isEmpty_q2()){
		for(int i=front_two+1; i<=rear_two; i++){
			cout<<que_two[i]<<" ";
		}
		cout<<"\n";
	}
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
