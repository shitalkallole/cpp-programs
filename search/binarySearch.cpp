//algo - binary search
//time - O(logn)
//space - O(logn)
#include<iostream>
#include<vector>
using namespace std;
int binarySearch(int searchEle,vector<int>&data,int ,int);

int main(){
	freopen("inputf.txt","r",stdin);
	freopen("outputf.txt","w",stdout);

	int n,i,search;
	cin>>n;
	vector<int> data(n);
	for(i=0;i<n;i++)
		cin>>data[i];

	cin>>search;

	if(binarySearch(search,data,0,n-1))
		cout<<"found";
	else
		cout<<"Not found";
	return 0;
}
int binarySearch(int searchEle,vector<int>&data,int start,int end){
	int mid;

	if(start<=end)
	{
		mid=(start+end)/2;
		if(data[mid]==searchEle)
			return 1;
		else if(searchEle<data[mid])
			end=mid-1;
		else
			start=mid+1;
		return binarySearch(searchEle,data,start,end);
	}
	return 0;
}