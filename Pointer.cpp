#include<bits/stdc++.h>
using namespace std;
int main(){
//  Static array Declaration [C++]
//	int a[10], *p;
//	p=a;
//	for(int i=0; i<10; i++){
//		cin>>*p; // OR cin>>*(p+i) 
//		p++;
//	}
//
//	for(int i=0; i<10; i++){
//		cout<<*p<<" ";
//		p++;
//	}

// Dynamic memory allocation (Run time allocation) [C++]
//	int *arr;
//	arr = new int[10];
//	for(int i=0; i<10; i++){
//		cin>>arr[i];
//	}
//	
//	for(int i=0; i<10; i++){
//		cout<<arr[i];
//	}

// Dynamic memory allocation (Run time allocation) [ C lang.]
	int *a;
	a = (int*)malloc(10*sizeof(int));
	for(int i=0; i<10; i++){
		cin>>a[i];
	}
	for(int i=0; i<10; i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
