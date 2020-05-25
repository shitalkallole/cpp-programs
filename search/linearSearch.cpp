//algo - linear search
//time - O(n)
//space - O(1)
#include<iostream>
#include<vector>
using namespace std;
int linearSearch(int searchEle,vector<int>&data);

int main(){
	freopen("inputf.txt","r",stdin);
	freopen("outputf.txt","w",stdout);

	int n,i,search;
	cin>>n;
	vector<int> data(n);
	for(i=0;i<n;i++)
		cin>>data[i];

	cin>>search;
	if(linearSearch(search,data))
			cout<<"Found";
	else
			cout<<"Not found";
	return 0;
}
int linearSearch(int searchEle,vector<int>&data){
	for(int ele:data)
		if(ele==searchEle)
			return 1;
	return 0;
}