#include<bits/stdc++.h>
using namespace std;

void minHeap(int root,int limit,vector<pair<pair<int,int>,int>> &edgeList);
void unionOp(int u,int v,vector<int> &parent);
int find(int v,vector<int> &parent);

int main(){
	freopen("inputf.txt","r",stdin);
	freopen("outputf.txt","w",stdout);

	int V,E,totalWeight=0;
	cin>>V>>E;

	vector<int> parent(V+1);
	vector<pair<pair<int,int>,int>> edgeList(E);
	//read all edges
	for(int i=0;i<E;i++)
		cin>>edgeList[i].first.first>>edgeList[i].first.second>>edgeList[i].second;

	//call minHeap on all except 0 for making my job easy
	for(int i=(E-1)/2;i>0;i--)
		minHeap(i,E,edgeList);

	//assign default values of parent
	for(int i=0;i<=V;i++)
		parent[i]=i;

	int n=E;
	while(n!=0){
		minHeap(0,n,edgeList);

		int p1,p2;
		p1=find(edgeList[0].first.first,parent);
		p2=find(edgeList[0].first.second,parent);
		if(p1!=p2){
			unionOp(p1,p2,parent);
			totalWeight+=edgeList[0].second;
			cout<<"["<<edgeList[0].first.first<<","<<edgeList[0].first.second<<"] = "<<edgeList[0].second<<"\n";	
		}
		n--;
		swap(edgeList[0],edgeList[n]);
	}

	cout<<"TotalWeight = "<<totalWeight;

	return 0;
}
int find(int v,vector<int> &parent){
	if(parent[v]==v)
		return v;
	return find(parent[v],parent);
}
void unionOp(int u,int v,vector<int> &parent){
	parent[v]=u;
}
void minHeap(int root,int limit,vector<pair<pair<int,int>,int>> &edgeList){
	int min = root;
	
	if(root*2+1<limit && edgeList[root*2+1].second<edgeList[min].second)
		min = root*2+1;
	if(root*2+2<limit && edgeList[root*2+2].second<edgeList[min].second)
		min = root*2+2;

	if(min!=root){
		swap(edgeList[root],edgeList[min]);
		minHeap(min,limit,edgeList);
	}
}