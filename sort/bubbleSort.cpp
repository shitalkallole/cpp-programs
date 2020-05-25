//algo - bubble sort
//time - O(n^2)
//space - O(1)
#include<iostream>
#include<vector>
using namespace std;
int main(){
	freopen("inputf.txt","r",stdin);
	freopen("outputf.txt","w",stdout);

	int n,i,j,temp,inside;
	cin>>n;
	vector<int> data(n);
	for(i=0;i<n;i++)
		cin>>data[i];

	for(i=0;i<n;i++){
		inside=1;
		for(j=0;j<n-1-i;j++){
			if(data[j]>data[j+1]){
				temp=data[j];
				data[j]=data[j+1];
				data[j+1]=temp;
				inside=0;
			}
		}
		if(inside)
			break;
	}
	for(i=0;i<n;i++)
		cout<<data[i]<<" ";
	return 0;

}