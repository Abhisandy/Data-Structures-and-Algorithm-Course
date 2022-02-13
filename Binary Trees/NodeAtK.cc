#include<bits/stdc++.h>

using namespace std;

class node{

public:
	int data;
	node * left;
	node *right;

	node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};



void levelOrderPrint(node * root){

	queue<node*> q;   //string node* not int otherwise we can't access childerns
	q.push(root);
	q.push(NULL);

	while(!q.empty()){

		node * temp = q.front();
		if(temp==NULL){
			cout<<endl;   //print next level in next line 
			q.pop();
			if(!q.empty()){   // if not last NULL push another NULL
				q.push(NULL);
			}
		}
		else{
			cout<<q.front()->data<<" ";
			q.pop();

			if(temp->left){
				q.push(temp->left);
			}
			if(temp->right){
				q.push(temp->right);
			}

		}

	}
	return;
}


void printAtLevelK(node * root, int k){
	if(root==NULL){
		return;
	}
	if(k==0){
		cout<<root->data<<" ";
	}
	printAtLevelK(root->left, k-1);
	printAtLevelK(root->right, k-1);
	return;
}

int printNodesAtDistanceK(node * root, node * target, int k){

	if(root==NULL){   //base case
		return -1;
	}

	if(root==target){   //found target node
		printAtLevelK(target, k);
		return 0;
	}

	int DL = printNodesAtDistanceK(root->left, target, k);
	if(DL!=-1){       //means target found in left subtree

		if(DL+1 == k){    //check if print root
			cout<<root->data;
		}
		else{
			printAtLevelK(root->right, k-2-DL);
		}
		return 1 + DL;
	}

	int RL = printNodesAtDistanceK(root->right, target, k);
	if(RL!=-1){       //means target found in right subtree

		if(RL+1 == k){    //check if print root
			cout<<root->data;
		}
		else{
			printAtLevelK(root->left, k-2-RL);
		}
		return 1 + RL;
	}

	return -1;
}


int main(){

	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->right = new node(6);
	root->left->right->left = new node(7);
	root->left->right->right = new node(8);
	root->left->right->right->left = new node(9);
	root->left->right->right->right = new node(10);

	levelOrderPrint(root);
	cout<<endl;
	
	//Target Node 5
	node* target = root->left->right;
	

	int k = 2;	
	printNodesAtDistanceK(root,target,k);
	cout<<endl;


	return 0;
}