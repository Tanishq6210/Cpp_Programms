#include<bits/stdc++.h>
using namespace std;

class node{
	node *prev;
	int data;
	node *succ;
	
	public:
	node *head = NULL ;
	node *tail = NULL;
	
	void insertBeg(int data){
		node *newnode = new node();
		newnode->data = data;
		newnode->prev = NULL;
		newnode->succ = NULL;
		
		if(head == NULL){
			head = newnode;
			return;
		}else{
			node *temp = head;
			head->prev = newnode;
			newnode->succ = head;
			head = newnode;
		}
	}

	void insertEnd(int data){
		node *newnode = new node;
		newnode->data = data;
		newnode->succ = NULL;
		newnode->prev = NULL;
		if(head == NULL){
			head = newnode;
		}else{
			node *temp = head;
			while(temp->succ != NULL){
				temp= temp->succ;
			}
			temp->succ = newnode;
			newnode->prev = temp;
		}
	}
		
	void insertMiddle(int data, int position){
		node *newnode = new node;
		newnode->data = data;
		newnode->succ = NULL;
		newnode->prev = NULL;
		if(head == NULL){
			head = newnode;
		}else{
			node *temp = head;
			int count = 0;
			while(count < position-1 && temp->succ != NULL){
				temp = temp->succ;
				count++;
			}
			newnode->succ = temp->succ;
			temp->succ->prev = newnode;
			newnode->prev = temp;
			temp->succ = newnode;
		}
	}

	void display(){
		node *temp = head;
		while(temp != NULL){
			cout<<temp->data<<" ";
			temp = temp->succ;
		}cout<<"\n";
	}

//	void deleteMiddle(int data){
//		if(head == NULL)
//			return ;
//		node *temp = head;
//		while(temp->data != data && temp->succ != NULL){
//			temp = temp->succ;
//		}
//		temp->prev->succ = temp->succ;
//		temp->succ->prev = temp->prev;
//		if(temp->data == data)
//			cout<<"Deleted item is "<<temp->data<<"\n";
//		else
//			cout<<data<<" is not present in the linked list.\n";
//	}
	
	int count(){
		node *temp = head;
		int count = 0;
		while(temp != NULL){
			temp = temp->succ;
			count++;
		}
		return count;
	}
//	void swap(){
//		node *temp = head;
//		node *last = NULL;
//		while(temp->succ != NULL){
//			temp = temp->succ;
//		}
//		last = temp;
//		temp = head;
//		int i = 0;
//		while(i<(count()/2)){
//			int data = temp->data;
//			temp->data = last->data;
//			last->data = data;
//			cout<<temp->data<<" "<<last->data<<"\n";
//			temp = temp->succ;
//			last = last->prev;
//			i++;
//		}
//	}

};


int main(){
	node obj;
	obj.insertEnd(1);
	obj.insertEnd(2);
	obj.insertEnd(4);
	obj.insertMiddle(3,2);
	obj.display();
	obj.deleteMiddle(5);
	obj.display();
	obj.swap();
	obj.display();
	return 0;
}
