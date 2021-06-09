#include<bits/stdc++.h>
using namespace std;

// Ques 1 (a)
//int main()
//{
//	int n;
//	cout<<"No. of elements in the array: "<<endl;
//	cin>>n;
//	int arr[n];
//	cout<<"Enter the elements of array: "<<endl;
//	for(int i=0; i<n; i++){
//		cin>>arr[i];
//	}
//	int s = sizeof(arr)/sizeof(arr[0]);
//	sort(arr,arr+s);
//	cout<<"Enter the number: "<<endl;
//	int x;
//	cin>>x;
//	int ans = 0;
//	int min = x;
//	for(int i=0; i<n; i++){
//		if( abs(arr[i]-x) >= min){
//			break;
//		}else{
//			ans = arr[i];
//			min = abs(arr[i]-x);
//		}
//	}
//	cout<<"The closest number is: "<<ans<<endl;
//	
//}


//Ques 1(b)
int main(){
	int arr[] = {14, 33, 27, 10, 35, 19, 42, 44};
	int i, key, j;
	int n = 8;
    for (i = 1; i < 3; i++)
    {
        key = arr[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    
    for(i=0; i<n; i++){
    	cout<<arr[i]<<" ";
	}
	return 0;
}
