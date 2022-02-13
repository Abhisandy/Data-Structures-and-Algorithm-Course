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


void printAtLevelK(vector<int> &v, node * root, int k){
	if(root==NULL){
		return;
	}
	if(k==0){
		v.push_back(root->data);
		return;
	}
	printAtLevelK(v, root->left, k-1);
	printAtLevelK(v, root->right, k-1);
	return;
}

int printNodesAtDistanceK(vector<int> &v, node * root, node * target, int k){

	if(root==NULL){   //base case
		return -1;
	}

	if(root==target){   //found target node
		printAtLevelK(v, target, k);
		return 0;
	}

	int DL = printNodesAtDistanceK(v, root->left, target, k);
	if(DL!=-1){       //means target found in left subtree

		if(DL+1 == k){    //check if print root
			v.push_back(root->data);
		}
		else{
			printAtLevelK(v, root->right, k-2-DL);
		}
		return 1 + DL;
	}

	int RL = printNodesAtDistanceK(v, root->right, target, k);
	if(RL!=-1){       //means target found in right subtree

		if(RL+1 == k){    //check if print root
			v.push_back(root->data);
		}
		else{
			printAtLevelK(v, root->left, k-2-RL);
		}
		return 1 + RL;
	}

	return -1;
}

vector<int> nodesAtDistanceK(node *root, node *target, int k){
    //return a SORTED vector of the nodes
    
    vector<int> result;
    printNodesAtDistanceK(result, root, target,k);
    sort(result.begin(),result.end());
    return result;
    
}


