#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("inputf.txt","r",stdin);
	freopen("outputf.txt","w",stdout);

	int v,e,s,d;
	cin>>v>>e;

	vector<vector<int>> adMatrix(v,vector<int>(v));
	queue<int> child;
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
		int ele = child.front();
		cout<<ele+1<<" ";
		child.pop();

		for(int j=0;j<v;j++){
			if(adMatrix[ele][j]==1 && visited[j]==0){
				visited[j]=1;
				child.push(j);
			}
		}
	}

	return 0;
}3