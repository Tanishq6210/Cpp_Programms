#include<iostream>
using namespace std;

class node{
public:
	int data;
	node *next;
	node *prev;

	node(int x){
		data = x;
		next = NULL;
		prev = NULL;
	}
};

node *head=NULL, *tail=NULL;

void insertEnd(int data)
{
	node* newnode = new node(data);
	if (head == NULL)
	{
		head = tail = newnode;
	}else{
		tail->next = newnode;
		newnode->prev = tail;
		tail = newnode;
	}
}

void insertBeg(int data)
{
	node* newnode = new node(data);

	if (head == NULL)
	{
		head = tail = newnode;
	}else{
		head->prev = newnode;
		newnode->next = head;
		head = newnode;
	}
}


void display(){
	node *temp = head;
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

void sumEven(){
	node *temp = head;
	int sum =  0;
	while(temp != NULL){
		if(temp->data % 2 == 0){
			sum+=temp->data;
		}		
		temp = temp->next;
	}
	cout<<sum;
}

void insertAtPos(int pos, int data){
	int i=1;
	if(pos==1) insertBeg(data);
	else{
		node *temp = head;
		node *newnode = new node(data);
		while(i<pos-1){
			temp = temp->next;
			i++;
		}
		newnode->prev = temp;
		newnode->next = temp->next;
		temp->next->prev = newnode;
		temp->next = newnode;
	}
}

void insertAfterPos(int pos, int data){
	int i=1;

	node *temp = head;
	node *newnode = new node(data);
	while(i<pos){
		temp = temp->next;
		i++;
	}
	newnode->prev = temp;
	newnode->next = temp->next;
	temp->next->prev = newnode;
	temp->next = newnode;
}

void reversePrint(){
	node *temp = tail;
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp = temp->prev;
	}
	cout<<endl;
}

void deleteBeg(){
	node *temp = head;
	if(head == NULL){
		cout<<"Empty list.\n";
	}else{
		cout<<"Deleted Element is: "<<temp->data<<endl;
		head = head->next;
		head->prev = NULL;
		delete temp;
	}
}


void deleteEnd(){
	node *temp = tail;
	if(tail == NULL) cout<<"Empty";
	else{
		tail = tail->prev;
		tail->next = NULL;
		cout<<"Deleted Element is: "<<temp->data<<endl;
		delete temp;
	}
}

void deleteAtPos(int pos){
	int i=1;
	node *temp = head;
	while(i<pos){
		temp = temp->next;
		i++;
	}
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	cout<<"Deleted Element is: "<<temp->data<<endl;
	delete temp;
}

int main()
{
	
	return 0;
}