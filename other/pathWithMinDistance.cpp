//space complexity= O(n^2) polynomial
#include<iostream>
#include<vector>
using namespace std;
int rec(int s,int d, vector<vector<int>> &roadMap,int city,vector<int>&visited,vector<int>&dp);
int main(){
	freopen("inputf.txt","r",stdin);
	freopen("outputf.txt","w",stdout);

	int city,road,i,j,s,d,v,min;
	cin>>city>>road;
	city+=1;

	vector<vector<int>> roadMap(city);
	for(i=0;i<city;i++)
		roadMap[i]=vector<int>(city);

	for(i=0;i<road;i++){
		cin>>s>>d>>v;
		roadMap[s][d]=v;
	}

	cin>>s>>d;
	vector<int> visited(city);
	vector<int> dp(city);
	min=rec(s,d,roadMap,city,visited,dp);
	cout<<"path:"<<min;
	return 0;
}
int rec(int s,int d, vector<vector<int>>&roadMap, int city, vector<int>&visited,vector<int>&dp){
	int i;
	int total=0;
	int min=0;
	visited[s]=1;

	for(i=1;i<city;i++){
		if(roadMap[s][i]!=0 && visited[i]==0)
		{
			if(dp[i]!=0)
				total=roadMap[s][i]+dp[i];
			else if(i==d)
				total=roadMap[s][i];
			else
				total=roadMap[s][i]+rec(i,d,roadMap,city,visited,dp);
		
			if(min==0)
				min=total;
			else
			{
				if(total<min)
					min=total;
			}
		}

	}
	visited[s]=0;
	dp[s]=min;
	return min;
}
