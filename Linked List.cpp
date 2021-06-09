#include<bits/stdc++.h>
using namespace std;

int n;
class node{
	public:
	string rno;
	int sem;
	node *next;
};

node *head = NULL;

void frontInsert(string r, int s){
	node *newnode = new node;
	newnode -> rno = r;
	newnode -> sem = s;
	newnode -> next = NULL;
	if(head == NULL){
		head = newnode;
	}else {
		newnode -> next = head;
		head = newnode;
	}
}

void backInsert(string r, int s){
	node *newnode = new node;
	newnode -> rno = r;
	newnode -> sem = s;
	newnode -> next = NULL;
	
	node *temp;
	temp = head;
	if(head == NULL){
		head = newnode;
	}else{
		while(temp -> next != NULL){
			temp = temp -> next;
		}
		temp -> next = newnode;
	}
}

void frontdelete(){
	if(head == NULL){
		cout<<"Linked List is Empty.\n";
		return;
	}
	node *temp;
	temp = head;
	head = head -> next;
	temp -> next = NULL;
	cout<<"Deleted data is: "<<temp -> rno<<" "<<temp -> sem;	
	
}

void backDelete(){
	node *temp = head;
	node *prev = NULL;
	while(temp -> next != NULL){
		prev = temp;
		temp = temp->next;
	}
	prev -> next = NULL;
	cout<<"Deleted data is: "<<temp -> rno<<" "<<temp -> sem;	
}

int length(){
	node *temp = head;
	int count=0;
	while(temp != NULL){
		count++;
		temp = temp -> next;
	}
	return count;
}

void display(){
	node *temp=head;
	while(temp != NULL){
		cout<<temp->rno<<" "<<temp->sem<<"\n";
		temp = temp->next;
	}
}

void middleInsert(string str, int s){
	node *newnode = new node();
	newnode->rno = str;
	newnode->sem = s;
	newnode->next = NULL;
	if(head == NULL)
		head = newnode;
	else{
		node *temp = head;
		int count = 0;
		while(count < n-1 && temp->next != NULL){
			count++;
			temp = temp->next;
		}
		newnode->next = temp->next;
		temp->next = newnode;
	}
}

void middleInsert(string str, int s, int data){
	node *newnode = new node();
	newnode->rno = str;
	newnode->sem = s;
	newnode->next = NULL;
	if(head == NULL)
		head = newnode;
	else{
		node *temp = head;
		while(temp->sem != data && temp->next != NULL){
			temp = temp->next;
		}
		newnode->next = temp->next;
		temp->next = newnode;
	}
}

void middleDelete(int del){
	node *temp, *prev;
	temp = head;
	prev = NULL;
	while(temp->sem != del && temp->next != NULL){
		prev = temp;
		temp = temp->next;
	}
	prev->next = temp->next;
	temp->next = NULL;
	cout<<"Deleted Element is "<<temp->rno<<" "<<temp->sem<<"\n";
}

int middleElement(){
	node *first = head;
	node *second = head;
	while(second->next->next != NULL && second->next != NULL){
		first=first->next;
		second=second->next->next;
	}
	return first->sem;
}

void rev(){
	node *prev = NULL;
	node *curr = head;
	node *succ = curr->next;
	while(succ != NULL){
		curr->next = prev;
		prev = curr;
		curr = succ;
		succ = succ->next;
	}
	curr->next = prev;
	head = curr;
}

void alternate(){
	node *temp = head;
	int i = 0;
	while(temp != NULL){
		if(i%2==0){
			cout<<temp->sem<<" ";
			temp = temp->next;
			i++;
		}
		else{
			temp = temp->next;
			i++;
			continue;
		}
	}
}

int main()
{
	backInsert("one",1);
	backInsert("two",2);
	backInsert("three",3);
	backInsert("four",4);
	backInsert("five",5);
	backInsert("six",6);
	backInsert("five",7);
	backInsert("six",8);
	backInsert("six",9);
	//cout<<middleElement();
	//rev();
	//display();
	
	alternate();
	return 0;
}
