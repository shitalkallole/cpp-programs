//algo - selection sort
//time - O(n^2)
//space - O(1)
#include<iostream>
#include<vector>
using namespace std;
int main(){
	freopen("inputf.txt","r",stdin);
	freopen("outputf.txt","w",stdout);

	int n,i,j,index,temp;
	cin>>n;
	vector<int> data(n);
	for(i=0;i<n;i++)
		cin>>data[i];

	for(i=0;i<n-1;i++){
		index=i;
		for(j=i+1;j<n;j++){
			if(data[j]<data[index])
				index=j;
		}
		temp=data[i];
		data[i]=data[index];
		data[index]=temp;
	}

	for(i=0;i<n;i++)
		cout<<data[i]<<" ";
	return 0;
}
