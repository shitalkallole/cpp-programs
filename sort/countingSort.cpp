//algo - counting sort
//max(data) = k
//min(data) = l
//max(data) = |m|
/*time - 
	if(contain both pos and neg)
		O(n+(k-l))
	else
		O(n+m)
*/
//space -O(n+k)
#include<iostream>
#include<vector>
using namespace std;


int main(){
	freopen("inputf.txt","r",stdin);
	freopen("outputf.txt","w",stdout);

	int n,i,temp,max,min,total,limit;
	
	cin>>n;
	vector<int> data(n);

	for(i=0;i<n;i++)
		cin>>data[i];

	max=data[0];
	min=data[0];

	for(i=1;i<n;i++){
		if(data[i]>max)
			max=data[i];
		if(data[i]<min)
			min=data[i];
	}

	if(min>=0 && max>=0)
	{
		total=max+1;
		min=0;
	}
	else if(min<=0 && max<=0){
		total=-min+1;
		min=-min;
	}
	else
	{
		total=(max-min)+1;
		min=-min;
	}

	vector<int> count(total);
	for(i=0;i<n;i++)
		count[data[i]+min]++;

	for(i=1;i<total;i++)
		count[i]+=count[i-1];

	vector<int> result(n);

	for(i=0;i<n;i++)
	{
		result[count[data[i]+min]-1]=data[i];
		count[data[i]+min]-=1;
	}

	for(i=0;i<n;i++)
		cout<<result[i]<<" ";

	return 0;
}