#include<iostream>
using namespace std;

class node{
public:
	int data;
	node *next;
	node(int x){
		data = x;
	}
};

node *tail = NULL;

int getLength(){
	node *temp = tail->next;
	int i=0;
	while(temp->next != tail->next){
		temp= temp->next;
		i++;
	}
	return i;
}

void insertEnd(int data){
	node *newnode = new node(data);

	if(tail == NULL){
		tail = newnode;
		tail->next = newnode;
	}else{
		newnode->next = tail->next;
		tail->next = newnode;
		tail = newnode;
	}
}

void insertBeg(int data){
	node *newnode = new node(data);
	if(tail == NULL){
		tail = newnode;
		tail->next = newnode;
	}else{
		newnode->next = tail->next;
		tail->next = newnode;
	}
}

void isnertAtPos(int pos, int data){
	if(tail == NULL)
		cout<<"Empty.";
	else{
		int i=1;
		node *newnode = new node(data);
		node *temp = tail->next;
		while(i<pos-1){
			i++;
			temp = temp->next;
		}
		newnode->next = temp->next;
		temp->next = newnode;
	}
}


void display(){
	if(tail == NULL)
		cout<<"Empty List.";
	else{
		node *temp = tail->next;
		while(temp->next != tail->next){
			cout<<temp->data<<" ";
			temp = temp->next;
		}cout<<temp->data<<"\n";
	}	
}

void deleteBeg(){
	node *temp = tail->next;
	tail->next = tail->next->next;
	cout<<"Deleted element: "<<temp->data<<endl;
	temp->next = NULL;
	delete temp;
}

void deleteEnd(){
	node *temp = tail->next;
	// node *toDelete;
	while(temp->next->next != tail->next){
		temp = temp->next;
	}
	// toDelete = tail;
	temp->next = tail->next;
	tail = temp;
	// delete toDelete;
}

int main(){
	
	insertBeg(1);
	insertEnd(2);
	insertEnd(4);
	insertEnd(5);
	insertEnd(6);
	insertEnd(7);
	insertEnd(8);
	insertEnd(9);
	insertBeg(0);
	isnertAtPos(3, 3);
	deleteBeg();
	deleteEnd();
	display();
	return 0;
}