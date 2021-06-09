#include <bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node *next;

	node(int x){
		data = x;
		next = NULL;
	}
};

node *rear = NULL;
node *front = NULL;

void enqueue(int data){
	node *newnode = new node(data);
	if(rear == NULL && front == NULL){
		rear = front = newnode;
	}else{
		rear->next = newnode;
		rear = newnode;
	}
}

void display(){
	node *temp = front;
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<"\n";
}

void dequeue(){
	node *temp = front;
	front = front->next;
	cout<<"Data deleted: "<<temp->data<<"\n";
	delete temp;	
}

void peek(){
	cout<<front->data<<"\n";
}
int main()
{   
	enqueue(1);
	enqueue(2);
	enqueue(3);
	dequeue();
	display();
	peek();
    return 0;
}
