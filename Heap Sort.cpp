#include<iostream>
using namespace std;
int a[]={11,2,9,13,57,25,17,1,90,30},n=10;
void buildheap(int v)
{
    int w=2*v+1;  //index of L child  w=3
    while(w<n)  //check if L child is present
    {
      if(w+1<n) //check if R child is present
      {
          if(a[w+1]>a[w])  
           w++;  //if R child is greater than L child, store the index of Rchild in w
      }    ///now w holds the index of the greater child
      if(a[v]<a[w])
      {
          int temp=a[v];
          a[v]=a[w];
          a[w]=temp;
      }
      v=w; 
      w=2*v+1;
    }
}

 
int main()
{
    int v,i;
    for(v=n/2-1;v>=0;v--)  //v=1,0 
      buildheap(v);
    int copy=n;
    while(n>1)   // 4>1
    {
        n--;
        int temp=a[0];
        a[0]=a[n];
        a[n]=temp;
        buildheap(0);
    }
    for(i=0;i<copy;i++)
      cout<<a[i]<<" ";
}
