#include <bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node *next;

	node(int d){
		data = d;
		next = NULL;
	}
};

node* top = NULL;

void push(int d){
	node *newnode = new node(d);

	if(top == NULL){
		top = newnode;
	}else{
		newnode->next = top;
		top = newnode;
	}
}

void pop(){
	if(top == NULL){
		cout<<"Stack underflow!";
	}else{
		node* temp = top;
		top = top->next;
		cout<<temp->data;
		temp->next = NULL;
		delete temp;
	}
}

void peek(){
	cout<<top->data<<endl;
}

void display(){
	node *temp = top;
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    push(5);
    push(4);
    push(3);
    push(2);
    push(1);
    pop();
    cout<<endl;
    display();
    return 0;
}
