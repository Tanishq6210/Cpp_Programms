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
	newnode -> next = head;
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


void increment(int n){
	node *temp;
	int j = 1;
	while(j<=n){
		temp = head;
		for(int i=1; i<14; i++){
			if(i%j == 0){
				temp->sem = temp->sem + 1;
			}
			temp = temp->next;
		}
		j++;
	}
}

void displaySem(){
	node *temp = head;
	while(temp != NULL){
		cout<<temp->sem<<" ";
		temp = temp->next;
	}
}

int main(){
	backInsert("1",0);
	backInsert("2",0);
	backInsert("3",0);
	backInsert("4",0);
	backInsert("5",0);
	backInsert("6",0);
	backInsert("7",0);
	backInsert("8",0);
	backInsert("9",0);
	backInsert("10",0);
	backInsert("11",0);
	backInsert("12",0);
	backInsert("13",0);
	increment(13);
	displaySem();	
	return 0;
}
