#include<bits/stdc++.h>
using namespace std;

int top=-1;
char arr[MAX];

void push(char data){
	top++;
	arr[top]=data;
}

char pop(){
	char x = arr[top];
	top--;
	return x;
}

bool isFull(){
	return top==MAX-1;
}

bool isEmpty(){
	return top==-1;
}

int main()
{
	string str;
	getline(cin,str);
	for(int i=0; i<str.length(); i++){
		char op = str[i];
		if(op=='(') push(op);
		else if(op==')') pop(op);
		else 
	}
	return 0;
}
