//algo - quick sort
//time - O(n^2)
//space - O(1)
#include<iostream>
#include<vector>
using namespace std;
void quickSort(vector<int> &data,int start,int end);
int main(){
	freopen("inputf.txt","r",stdin);
	freopen("outputf.txt","w",stdout);

	int n,i;
	cin>>n;
	vector<int> data(n);
	for(i=0;i<n;i++)
		cin>>data[i];

	quickSort(data,0,n-1);

	for(int x:data)
		cout<<x<<" ";
	return 0;
}

void quickSort(vector<int> &data,int start,int end){
	int pivot,temp;
	if(start<end){
		pivot=start;


		int sI=start;
		int eI=end;
		start+=1;

		
		while(1)
		{
			while(start<=end && data[start]<=data[pivot]){
				start++;
			}
			while(end>=start && data[end]>data[pivot]){
				end--;
			}
			if(start<=end){
				temp=data[start];
				data[start]=data[end];
				data[end]=temp;

				start++;
				end--;
			}
			else{
				temp=data[pivot];
				data[pivot]=data[end];
				data[end]=temp;

				break;
			}
		}
		quickSort(data,sI,end-1);
		quickSort(data,end+1,eI);
	}
}
