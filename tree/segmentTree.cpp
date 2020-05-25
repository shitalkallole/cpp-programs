#include<bits/stdc++.h>
using namespace std;

vector<int> getAllocatedMem(int n);
int buildSegmentTree(vector<int> &result,int root,int limit,vector<int> &values,int start,int end,int size);
int rangeMinQuery(vector<int>&result,int rS,int rE,int s,int e,int root);
int main(){
	freopen("inputf.txt","r",stdin);
	freopen("outputf.txt","w",stdout);

	int n,i,rS,rE,queryCount;
	cin>>n;

	vector<int> data(n);

	for(i=0;i<n;i++)
		cin>>data[i];

	vector<int> result = getAllocatedMem(n);
	buildSegmentTree(result,0,result.size(),data,0,((result.size()+1)/2)-1,data.size());
	
	cin>>queryCount;

	while(queryCount--){
		cin>>rS>>rE;
		cout<<"\nMin["<<rS<<" , "<<rE<<"] :"<<rangeMinQuery(result,rS,rE,0,((result.size()+1)/2)-1,0);	
	}
	return 0;
}

int rangeMinQuery(vector<int>&result,int rS,int rE,int s,int e,int root){
	if(s>=rS && e<=rE)
		return result[root];
	else if(s>rE || e<rS)
		return INT_MAX;
	int mid;
	mid=(s+e)/2;

	int left = rangeMinQuery(result,rS,rE,s,mid,root*2+1);
	int right = rangeMinQuery(result,rS,rE,mid+1,e,root*2+2);

	return left<right?left:right;
}
int buildSegmentTree(vector<int> &result,int root,int limit,vector<int> &values,int start,int end,int size){
	int minLeft,minRight;
	int mid;

	mid = (start+end)/2;
	if((root*2+1<limit) && (root*2+2<limit)){
		minLeft = buildSegmentTree(result,root*2+1,limit,values,start,mid,size);
		minRight = buildSegmentTree(result,root*2+2,limit,values,mid+1,end,size);
		result[root] = minLeft<minRight?minLeft:minRight;
	}
	else{
		if(start<size)
			result[root] = values[start];
		else
			result[root] = INT_MAX;
	}
	return result[root];
}
vector<int> getAllocatedMem(int n){
	int ans = 1;
	while(n>ans)
		ans*=2;
	ans=ans*2-1;

	vector<int> result(ans);//consider default val to 0
	return result;
}
