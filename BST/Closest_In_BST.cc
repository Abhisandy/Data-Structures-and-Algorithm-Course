#include<bits/stdc++.h>

using namespace std;

class Node{
public:
	int key;
	Node *left;
	Node *right;

	Node(int data){
		key = data;
		left = NULL;
		right = NULL;
	}
};

Node * insert(Node * root, int key){

	if(root==NULL){
		return new Node(key);
	}

	if(key< root->key){
		root->left = insert(root->left, key);
	}
	else{
		root->right = insert(root->right, key);
	}
	return root;     //link update everytime
}

void printInorder(Node* root){

	if(root==NULL){
		return;
	}
	printInorder(root->left);
	cout<<root->key<<" ";
	printInorder(root->right);
}

int closest(Node * root, int target){

	int diff = INT_MAX;
	int close;

	Node * temp = root;
	while(temp!=NULL){

		int current_diff = abs(temp->key - target);

		if(current_diff == 0){
			return temp->key;
		}

		if(current_diff < diff){
			diff = current_diff;
			close = temp->key;
		}

		if(temp->key > target){
			temp = temp -> left;
		}
		else{
			temp = temp -> right;
		}

	}
	return close;
}

int main(){
	Node * root = NULL;
	int arr[] = {8,3,10,1,6,14,4,7,13};

	for(int x: arr){
		root = insert(root, x);
	}
	printInorder(root);
	cout<<endl;
	auto res = closest(root, 16); //root, target
	cout<<res;
	return 0;
}