#include<bits/stdc++.h>
using namespace std;
int buildSegmentTree(vector<int> &result,int root,int limit,vector<int> &data,int start,int end,int dataSize);
vector<int> getMemAllocated(int n);
int rangeQuerySum(vector<int> &result,int root,int start,int end,int rS,int rE);
int updateQuery(vector<int> &result,int root,int start,int end,int rS,int rE,int value);

int main(){
	freopen("inputf.txt","r",stdin);
	freopen("outputf.txt","w",stdout);


	int n;
	cin>>n;

	vector<int> data(n);

	for(int i=0;i<n;i++)
		cin>>data[i];

	vector<int> result = getMemAllocated(n);
	buildSegmentTree(result,0,result.size(),data,0,(result.size()+1)/2-1,data.size());

	int query,rS,rE,value,op;
	cin>>query;

	while(query--){
		cin>>op;
		switch(op){
			case 1:
					cin>>rS>>rE;
					cout<<"sum :"<<rangeQuerySum(result,0,0,(result.size()+1)/2-1,rS,rE)<<" \n";
					break;
			case 2:
					cin>>rS>>value;
					rE=rS;
					updateQuery(result,0,0,(result.size()+1)/2-1,rS,rE,value);
					cout<<"Updated Data : ";
					for(int i=0;i<result.size();i++)
						cout<<result[i]<<" ";
					cout<<"\n";
					break;
		}
	}
	return 0;
}

int updateQuery(vector<int> &result,int root,int start,int end,int rS,int rE,int value){
	int update;
	if(start>=rS && end<=rE){
		update = value - result[root];
		result[root] = value;
		return update;
	}
	else if(end<rS || start>rE)
		return 0;
	int mid;
	mid = (start+end)/2;
	update = updateQuery(result,root*2+1,start,mid,rS,rE,value)+updateQuery(result,root*2+2,mid+1,end,rS,rE,value);
	result[root] = result[root] + update;
	
	return update; 
}
int rangeQuerySum(vector<int> &result,int root,int start,int end,int rS,int rE){
	if(start>=rS && end<=rE)
		return result[root];
	else if(end<rS || start>rE)
		return 0;
	int mid;
	mid = (start+end)/2;
	return rangeQuerySum(result,root*2+1,start,mid,rS,rE)+rangeQuerySum(result,root*2+2,mid+1,end,rS,rE);
}
int buildSegmentTree(vector<int> &result,int root,int limit,vector<int> &data,int start,int end,int dataSize){
	int mid;
	mid = (start + end)/2;
	if(root*2+1<limit)
		result[root]=buildSegmentTree(result,root*2+1,limit,data,start,mid,dataSize)+buildSegmentTree(result,root*2+2,limit,data,mid+1,end,dataSize);
	else if(start<dataSize)
		result[root] = data[start];

	return result[root];
}
vector<int> getMemAllocated(int n){
	int ans=1;
	while(n>ans)
		ans*=2;

	ans = ans*2-1;
	vector<int> result(ans,0);

	return result;
}