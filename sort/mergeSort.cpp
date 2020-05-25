//algo - merge sort
//time - O(nlogn)
//space - O(n)
#include<iostream>
#include<vector>
using namespace std;
void mergeSort(vector<int>&data,int start,int end);
int main(){
	freopen("inputf.txt","r",stdin);
	freopen("outputf.txt","w",stdout);

	int n,i;
	cin>>n;
	vector<int> data(n);
	for(i=0;i<n;i++)
		cin>>data[i];

	mergeSort(data,0,n-1);
	
	for(int ele:data)
		cout<<ele<<" ";
	return 0;
}

void mergeSort(vector<int>&data,int start,int end){
	int mid;
	if(start!=end){
		mid=start+(end-start)/2;//to avoid overflow

		mergeSort(data,start,mid);
		mergeSort(data,mid+1,end);

		vector<int> arr1;
		vector<int> arr2;

		int k,i,j;
		
		for(i=start;i<=mid;i++)
			arr1.push_back(data[i]);
		for(i=mid+1;i<=end;i++)
			arr2.push_back(data[i]);

		int arr1Len=arr1.size();
		int arr2Len=arr2.size();
		i=j=0;
		k=start;

		while(i<arr1Len && j<arr2Len){
			if(arr1[i]>arr2[j]){
				data[k]=arr2[j];
				j++;
			}
			else{
				data[k]=arr1[i];
				i++;
			}
			k++;
		}

		while(i<arr1Len)
		{
			data[k]=arr1[i];
			i++;
			k++;
		}
		while(j<arr2Len){
			data[k]=arr2[j];
			j++;
			k++;
		}
	}
}