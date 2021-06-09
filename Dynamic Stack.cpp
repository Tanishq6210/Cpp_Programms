#include<bits/stdc++.h>
using namespace std;

class node{
	int data;
	node *next;
	
	public:
		
		node *top = NULL;
		
		void push(int data){
			node *newnode = new node();
			newnode->data = data;
			newnode->next = NULL;
			
			if(top == NULL)
				top = newnode;
			else{
				newnode->next = top;
				top = newnode;
			}	
		}
		
		void display(){
			if(top == NULL)
				cout<<"Stack Empty.";
			else{
				node *temp = top;
				while(temp != NULL){
					cout<<temp->data<<" ";
					temp = temp->next;
				}
				cout<<"\n";
			}
		}

		int pop(){
			node *temp = top;
			int x = temp->data;
			delete(temp);
			top = top->next;
			return x;
		}
};


int main(){
	node obj;
	obj.push(1);
	obj.push(2);
	obj.push(3);
	obj.push(4);
	obj.push(5);
	obj.push(6);
	obj.display();
	cout<<obj.pop();
	return 0;
}
