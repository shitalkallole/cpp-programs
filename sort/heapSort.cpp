//algo - heap sort
/*time : 
	-heapify takes O(logn) comparison
	-we call heapify n/2 times for building max_heap so n/2*logn
	-we call again heapify for (n-1) elemens ~ n so n*logn
	-so f(n)=n/2*logn + n*logn ----- (n/2 ~ n)
			=n*logn+n*logn
			=2(n*logn)         -----(we can remove number while writing complexity)
			=nlogn
*/
//space - O(1)
#include<iostream>
#include<vector>
using namespace std;
void heapify(vector<int> &data,int index,int n);

int main(){
	freopen("inputf.txt","r",stdin);
	freopen("outputf.txt","w",stdout);

	int n,i,temp;
	
	cin>>n;
	vector<int> data(n);

	for(i=0;i<n;i++)
		cin>>data[i];

	for(i=(n/2)-1;i>=0;i--)//creating maxHeap
		heapify(data,i,n);

	for(i=n;i>1;i--)
	{
		swap(data[0],data[i-1]);
		heapify(data,0,i-1);
	}
	for(int x:data)
		cout<<x<<" ";

	return 0;
}
void heapify(vector<int> &data,int index,int n){
	int largest,temp;
	largest=index;

	if((index*2+1)<n && data[largest]<data[index*2+1])
		largest=index*2+1;

	if((index*2+2)<n && data[largest]<data[index*2+2])
		largest=index*2+2;

	if(largest!=index)
	{
		temp=data[index];
		data[index]=data[largest];
		data[largest]=temp;

		heapify(data,largest,n);
	}
}