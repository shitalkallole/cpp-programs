#include<bits/stdc++.h>
using namespace std;

int getMin(vector<int> &length,vector<int> &visited,int V);
int main(){
	freopen("inputf.txt","r",stdin);
	freopen("outputf.txt","w",stdout);

	int V,E,s,d,w;
	cin>>V>>E;

	vector<vector<int>> adMatrix(V,vector<int>(V));

	for(int j=0;j<E;j++){
		cin>>s>>d>>w;
		adMatrix[s-1][d-1]=w;
	}

	vector<int> visited(V);
	vector<int> length(V,-1);
	vector<int> prev(V);

	//assign default values
	length[0]=0;
	
	int vertex;
	while((vertex = getMin(length,visited,V))>=0){
		for(int j=0;j<V;j++){
			if(adMatrix[vertex][j]!=0){
				int relax = length[vertex]+adMatrix[vertex][j];	
				if(length[j]==-1 || length[j]>relax){
					length[j]=relax;
					prev[j]=vertex;
				}
			}
		}
		visited[vertex]=1;
	}

	for(int j=0;j<V;j++){
		cout<<j+1<<":"<<length[j]<<"\n";
		cout<<"path:";
		int p = j;
		while(p!=0){
			cout<<p+1<<"<-";
			p=prev[p];
		}
		cout<<"1\n";
	}
	return 0;
}		
int getMin(vector<int> &length,vector<int> &visited,int V){
	int min=INT_MAX,vertex;
	int status=0;

	for(int i=0;i<V;i++){
		if(length[i]!=-1&&visited[i]==0){
			status=1;
			if(min>length[i]){
				min=length[i];
				vertex=i;
			}
		}
	}
	if(status)
		return vertex;
	return -1;
}