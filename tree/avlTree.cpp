#include<iostream>
#include<vector>
using namespace std;


struct Node{
	int element;
	int height;
	struct Node *left;
	struct Node *right;
	
	Node(int e){
		element=e;
		height=1;
		left=NULL;
		right=NULL;
	}
};

Node* insertEleInBST(int,Node*);
void preorder(Node*);
Node* rotateRight(Node*);
Node* rotateLeft(Node*);
int getBalanceFactor(int,int);
int getMax(int,int);
int getHeight(Node*);


int main(){
	freopen("inputf.txt","r",stdin);
	freopen("outputf.txt","w",stdout);

	struct Node *root=NULL;

	int n,i;
	cin>>n;
	vector<int> data(n);
	for(i=0;i<n;i++)
		cin>>data[i];

	for(i=0;i<n;i++){
		root=insertEleInBST(data[i],root);
		cout<<"After Inserting Node "<<data[i]<<" (Preorder):\n";preorder(root);cout<<"\n";
		cout<<"---------------------------------\n";
	}
}
Node* rotateRight(Node *x){
	Node *y = x->left;
	x->left=y->right;
	y->right=x;

	x->height=1+getMax(getHeight(x->left),getHeight(x->right));
	return y;
}
Node* rotateLeft(Node *x){
	Node *y=x->right;
	x->right=y->left;
	y->left=x;

	x->height=1+getMax(getHeight(x->left),getHeight(x->right));
	return y;
}
int getBalanceFactor(int hL,int hR){
	return hL-hR;
}
int getMax(int heightLeft,int heightRight){
	return heightLeft>heightRight?heightLeft:heightRight; 
}
int getHeight(Node *temp){
	if(temp==NULL)
		return 0;
	return temp->height;
}
Node* insertEleInBST(int ele,Node *root){
	if(root==NULL)
		return new Node(ele);

	if(ele<root->element)
		root->left = insertEleInBST(ele,root->left);
	else
		root->right = insertEleInBST(ele,root->right);


	int balanceFactor = getBalanceFactor(getHeight(root->left),getHeight(root->right));

	if(balanceFactor>1){
		if(ele<root->left->element)
			root = rotateRight(root);
		else{
			root->left = rotateLeft(root->left);
			root =rotateRight(root);
		}
	}
	if(balanceFactor<-1){
		if(ele>root->right->element)
			root = rotateLeft(root);
		else{
			root->right = rotateRight(root->right);
			root = rotateLeft(root);
		}
	}

	root->height = 1+getMax(getHeight(root->left),getHeight(root->right));
	return root;
}
void preorder(Node *root){
	if(root!=NULL){
		cout<<root->element<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}