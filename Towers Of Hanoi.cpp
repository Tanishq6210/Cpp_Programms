#include<iostream>
using namespace std;
void towers( int n, char start, char end, char inter)
{          
     if(n==1)  
     {
      cout<<"move disk 1"<<" from "<<start<<" to  "<<end<<"\n";
       return;
     }       
     towers(n-1,start,inter,end);  
    cout<<"move disk "<<n<<" from "<<start<<" to  "<<end<<"\n";
     towers(n-1, inter,end,start);  
}           
int main()
{
    char start='A', end='C', inter='B';
    int n;
    cout<<"enter the number of disks u want to move\n";
    cin>>n;
    towers(n,start,end,inter);
    return 0;
}
