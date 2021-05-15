class BIT
{
public:
	int n;
	vector<int> tree;


	// pass n as it is means if userdata is of size 4 then n=4 must be passed
	BIT(int n, vector<int>&userData){
		this->n =  n;

		//allocate n+1 because index 0 is responsible for 0 values
		vector<int> data(n+1);
		tree = data;

		//build initial tree
		for(int i=0;i<n;i++){
			int index = i+1;
			while(index<=n){
				tree[index] = tree[index]+userData[i];	 //just change this operation according to your need
				index = getParent(index);
			}
		}
	}

	/*based on 1-indexing, so pass 1 - based index.*/
	int rangeGet(int index){
		int result = 0;
		while(index>0){
			result = result + tree[index];				//just change this operation according to your need
			index = getNext(index);
		}

		return result;
	}
	/*based on 1-indexing, so pass 1 - based index.
	pls pass correct value to update, ex- if earlier it has 5 (and if this BIT used for add operation),
	and if new value is 7 then you need to pass 2. if new value is 3 then you need to pass -2.*/
	void rangeUpdate(int index, int value){
		while(index<=n){
			tree[index] = tree[index] + value;			//just change this operation according to your need
			index = getParent(index);
		}
	}

	int getParent(int index){
		return (index+(index&(~index+1)));//i+=i&-i
	}
	int getNext(int index){
		return (index-(index&(~index+1)));//i-=i&-i
	}
};