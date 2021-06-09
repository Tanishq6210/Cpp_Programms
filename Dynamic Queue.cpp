#include<bits/stdc++.h>
using namespace std;

class node{
	int data;
	node *next;
	public:
		node *front = NULL;
		node *rear = NULL;
		
		void enqueue(int data){
			node *newnode = new node();
			newnode->data = data;
			newnode->next = NULL;
			
			if(rear == NULL && front == NULL){
				rear = newnode;
				front = newnode;
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

		int dequeue(){
			if(front == NULL){
				cout<<"Queue is empty, try entering some elements.";
				return 0;
			}else{
				node *temp = front;
				int x = temp->data;
				front = front->next;
				delete(temp);
				return x;
			}
		}
};

int main(){
	node obj;
	obj.enqueue(1);
	obj.enqueue(2);
	obj.enqueue(3);
	obj.enqueue(4);
	obj.enqueue(5);
	obj.display();
	cout<<obj.dequeue();
	return 0;
}
