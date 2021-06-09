#include<bits/stdc++.h>
using namespace std;

	vector<int> rotate(vector<int> a, int x) {
		
		if(x>=0) {
			for(int i=x; i>0; i--) {
				int temp = a[a.size()-1];
				a.pop_back();
				a.insert(a.begin(),temp);
			}
			
		}else {
			for(int i=abs(x); i>0; i--) {
				int temp = a[0];
				a.erase(a.begin());
				a.push_back(temp);
			}
		}
		return a;
	}
	
int main(){
	int n;
	cin>>n;
	vector<int> v;
	for(int i=0; i<n; i++){
		int temp ;
		cin>>temp;
		v.push_back(temp);
	}
	int q;
	cin>>q;
	int querry[q];
	for(int i=0; i<q; i++){
		cin>>querry[i];
	}
	
	for(int i=0; i<q; i++){
		vector<int> t = rotate(v,querry[i]);
		v.insert(v.end(), t.begin(), t.end());
		for (int i = 0; i < v.size(); ++i)
		{
			cout<<v[i]<<" ";
		}
		cout<<"\n"<<accumulate(v.begin(),v.end(),0)<<endl;
	}

	return 0;
}
