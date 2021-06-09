#include<bits/stdc++.h>
#define MAX 30
using namespace std;

int top;
int arr[MAX];
void init(){
	top = -1;
}

void push(int data)
{
	top++;
	arr[top]=data;
}

int pop()
{
	return arr[top--];
}

int eval(int d1, int d2, char sym){
	int r;
	switch(sym)
	{
		case '+':
			r = d1+d2;
			break;
		case '-':
			r = d1-d2;
			break;
		case '*':
			r = d1*d2;
			break;
		case '/':
			r = d1/d2;
			break;
		case '%':
			r = d1%d2;
			break;
		default:
			break;
	}
	return r;
}
int main()
{
	int i, j, val, opd1, opd2;
	string post;// "34+"
	cout<<"Enter the postfix expression to the evaluation\n";
	getline(cin,post);// To get the input string including space.
	i=post.length();// 3
	init();
	for(j=0; j<i; j++) // "34+  // ab+
	{
		if((post[j]==' ') || (post[j]=='\t'))
		continue;
		else if(isdigit(post[j]))
		{
			val=post[j]-48;/* To convert character digit to numeric digit 
			if character digit is '2' var = '2' - '0' = 2 or 
			50 - 48 = 2*/				
			push(val);
		}
		else if(isalpha(post[j]))
		{
			cout<<"Enter the value of "<<post[j];
			cin>>val;
			push(val);
		}
		else
		{
			opd2 = pop();
			opd1 = pop();
			push(eval(opd1, opd2, post[j]));
		}
	}
	cout<<"The answer we go on solving the postfix expressio is: "<<pop();
	return 0;
}
