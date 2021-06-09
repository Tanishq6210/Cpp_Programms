#include<iostream>
#include<math.h>
using namespace std;
struct toh
{
	int count;
	int disks[20];
};
struct toh arr[3];
int main()
{
	string A,B,C;
    int x=0,y=1,z=2;
	int n,i;
	cout<<"ENTER THE NUMBER OF DISKS \n";
	cin>>n;
	arr[0].count=n;
	arr[1].count=0;
	arr[2].count=0;
	for(i=0;i<n;i++)
	  arr[0].disks[i]=n-i;
	int moves=(int)pow(2,n)-1;
	A="source";
	B="intermediate";
	C="destination";
	if (n%2==0)
	{
		B="destination";
		C="intermediate";
		y=2;
		z=1;
    }
		for(i=1;i<=moves;i++)
		{
			if (i%3==1)
			{
				if (arr[x].count==0)
				    {
				    	
				    	arr[x].disks[arr[x].count]=arr[z].disks[arr[z].count-1];
				    	cout<<"move"<<arr[z].disks[arr[z].count-1]<<"from"<<C<<"to"<<A<<"\n";
				    	arr[z].count--;
				    	arr[x].count++;
				   
					}
				else if (arr[z].count==0)
				{
					arr[z].disks[arr[z].count]=arr[x].disks[arr[x].count-1];
					cout<<"move"<<arr[x].disks[arr[x].count-1]<<"from"<<A<<"to"<<C<<"\n";
					arr[x].count--;
					arr[z].count++;
			
				}
				else if (arr[x].disks[arr[x].count-1]< arr[z].disks[arr[z].count-1])
				{
						arr[z].disks[arr[z].count]=arr[x].disks[arr[x].count-1];
						cout<<"move"<<arr[x].disks[arr[x].count-1]<<"from"<<A<<"to"<<C<<"\n";
						arr[x].count--;
						arr[z].count++;
				
					}
					else if (arr[z].disks[arr[z].count-1]< arr[x].disks[arr[x].count-1])
					{
						arr[x].disks[arr[x].count]=arr[z].disks[arr[z].count-1];
						cout<<"move"<<arr[z].disks[arr[z].count-1]<<"from"<<C<<"to"<<A<<"\n";
						arr[z].count--;
						arr[x].count++;
				
					}
				}
				
			else if (i%3==2)
			{
				if (arr[x].count==0)
				{
					arr[x].disks[arr[x].count]=arr[y].disks[arr[y].count-1];
					cout<<"move"<<arr[y].disks[arr[y].count-1]<<"from"<<B<<"to"<<A<<"\n";
					arr[y].count--;
					arr[x].count++;
				    
					
				}
					else if (arr[y].count==0)
				{
					arr[y].disks[arr[y].count]=arr[x].disks[arr[x].count-1];
					cout<<"move"<<arr[x].disks[arr[x].count-1]<<"from"<<A<<"to"<<B<<"\n";
					arr[y].count++;
					arr[x].count--;
				
				}
				else if (arr[x].disks[arr[x].count-1]<arr[y].disks[arr[y].count-1])
				{
					arr[y].disks[arr[y].count]=arr[x].disks[arr[x].count-1];
						cout<<"move"<<arr[x].disks[arr[x].count-1]<<"from"<<A<<"to"<<B<"\n";
						arr[x].count--;
						arr[y].count++;
			    }
					else if (arr[y].disks[arr[y].count-1]<arr[x].disks[arr[x].count-1])
					{
						arr[x].disks[arr[x].count]=arr[y].disks[arr[y].count-1];
						cout<<"move"<<arr[y].disks[arr[y].count-1]<<"from"<<B<<"to"<<A<"\n";
						arr[y].count--;
						arr[x].count++;
				
					}
				}
			else if (i%3==0)
			{
				if (arr[z].count==0)
				{
					arr[z].disks[arr[z].count]=arr[y].disks[arr[y].count-1];
						cout<<"move"<<arr[y].disks[arr[y].count-1]<<"from"<<B<<"to"<<C<<"\n";
					arr[y].count--;
					arr[z].count++;
					
				}
					else if (arr[y].count==0)
				{
						arr[y].disks[arr[y].count]=arr[z].disks[arr[z].count-1];
						cout<<"move"<<arr[z].disks[arr[z].count-1]<<C<<"to"<<B<<"\n";
					arr[y].count++;
					arr[z].count--;
			
				}
				else if (arr[z].disks[arr[z].count-1]<arr[y].disks[arr[y].count-1])
				{
						arr[y].disks[arr[y].count]=arr[z].disks[arr[z].count-1];
						cout<<"move"<<arr[z].disks[arr[z].count-1]<<"from"<<C<<"to"<<B<<"\n";
						arr[z].count--;
						arr[y].count++;
				
					}
					else if (arr[y].disks[arr[y].count-1]<arr[z].disks[arr[z].count-1])
					{
						arr[z].disks[arr[z].count]=arr[y].disks[arr[y].count-1];
						cout<<"move"<<arr[y].disks[arr[y].count-1]<<"from"<<B<<"to"<<C<<"\n";
						arr[z].count++;
						arr[y].count--;
					
					}
			}
	
	}
}
