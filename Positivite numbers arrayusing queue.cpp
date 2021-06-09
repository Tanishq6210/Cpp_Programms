#include<bits/stdc++.h>
#define MAX 10
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

void removeNegative(){
	int n = MAX;
	while(n != 0){
		int temp = dequeue();
		if(temp >=0 ){
			enqueue(temp);
		}
		n--;
	}
}
int main(){
	for(int i=0; i<MAX; i++){
		int element;
		cin>>element;
		enqueue(element);
	}
	removeNegative();
	display();
	return 0;
}
