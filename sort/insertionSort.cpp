//algo - Insertion sort
//time - O(n^2)
//space - O(1)
#include<iostream>
#include<vector>
using namespace std;
int main(){
	freopen("inputf.txt","r",stdin);
	freopen("outputf.txt","w",stdout);

	int n,i,j,ele,temp;
	cin>>n;
	vector<int> data(n);
	for(i=0;i<n;i++)
		cin>>data[i];

	for(i=0;i<n;i++){
		ele=data[i];
		j=i-1;
		while(j>=0){
			if(data[j]>ele)
				data[j+1]=data[j];
			else
				break;
			j--;
		}		
		j+=1;
		data[j]=ele;
	}

	for(i=0;i<n;i++)
		cout<<data[i]<<" ";
	return 0;
}