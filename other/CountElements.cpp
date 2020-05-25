//time complexity : linear time complexity O(n)
//space complexity: constant space complexity O(1)
#include<iostream>
#include<vector>
using namespace std;

int main(){
	freopen("inputf.txt","r",stdin);
	freopen("outputf.txt","w",stdout);

	int n,i;
	cin>>n;

	vector<int> data(n);
	for (i = 0; i < n; i++)
		cin>>data[i];

	for(i=0;i<n;i++)
		data[data[i]%n]+=n;

	for(i=0;i<n;i++){
		if(data[i]/n!=0)
			cout<<i<<" : "<<data[i]/n<<endl;
	}

	return 0;
}