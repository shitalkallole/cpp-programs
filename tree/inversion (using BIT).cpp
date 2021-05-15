#include<bits/stdc++.h>
using namespace std;

class BIT
{
public:
	int n;
	vector<int> data;
	BIT(int n){
		this->n=n;
		vector<int> temp(n+1);
		data=temp;
	}
	int indexGet(int start){
		int sum=0;
		while(start>0){
			sum+=data[start];
			start-=start&(-start);
		}
		return sum;
	}
	void indexUpdate(int start,int val){
		while(start<=n){
			data[start]+=val;
			start+=start&(-start);
		}
	}
};
int main(){
	freopen("inputf.txt","r",stdin);
  	freopen("outputf.txt","w",stdout);

  	int n;
  	cin>>n;

  	int maximum=0;
  	vector<int> data(n);
  	for(int i=0;i<n;i++){
  		cin>>data[i];
  		maximum=max(maximum,data[i]);
  	}

  	BIT bit(maximum);
  	//BIT START
  	int ans=0;
  	for(int i=n-1;i>=0;i--){
  		ans+=bit.indexGet(data[i]);
  		bit.indexUpdate(data[i],1);
  	}
  	cout<<ans<<endl;
}
