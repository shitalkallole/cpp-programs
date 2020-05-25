//time complexity : linear time complexity O(n)
//space complexity: linear space complexity O(n)
#include<iostream>
#include<vector>
#include<map> 
using namespace std;

int main(){
	freopen("inputf.txt","r",stdin);
	freopen("outputf.txt","w",stdout);

	int n,i,sum=0,k,start,end,got=0,totalCount=0,temp;
	map<int,int> search;

	cin>>n>>k;

	vector<int> data(n);
	for (i = 0; i < n; i++)
		cin>>data[i];


	for(i=0;i<n;i++){
		auto itr =search.find(sum+k);
		if(itr!=search.end())
			itr->second=itr->second+1;
		else
			search.insert(pair<int,int>(sum+k,1));

		sum+=data[i];

		itr =search.find(sum);
		if(itr!=search.end()){
			totalCount+=itr->second;
			got=1;
		}
	}
	cout<<"Total no of subarray which has sume = "<<k<<" is :"<<totalCount;

	return 0;
}