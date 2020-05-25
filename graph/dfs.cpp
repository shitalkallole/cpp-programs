#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("inputf.txt","r",stdin);
	freopen("outputf.txt","w",stdout);

	int v,e,s,d;
	cin>>v>>e;

	vector<vector<int>> adMatrix(v,vector<int>(v));
	stack<int> child;
	vector<int> visited(v);

	for(int i=0;i<e;i++)
	{
		cin>>s>>d;
		adMatrix[s-1][d-1]=1;
		adMatrix[d-1][s-1]=1;
	}

	visited[0]=1;
	child.push(0);

	while(!child.empty()){
		int ele = child.top();
		cout<<ele+1<<" ";
		child.pop();

		for(int i=0;i<v;i++)
		{
			if(adMatrix[ele][i]==1 && visited[i]==0){
				visited[i]=1;
				child.push(i);
			}
		}
	}
	return 0;
}