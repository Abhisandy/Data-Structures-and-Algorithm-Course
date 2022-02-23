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

Node * InorderSuccessor(Node * root, Node * target){   //grtting address of target as value can be same

	if(target->right != NULL){

		Node * temp  = target->right;
		while(temp->left!=NULL){
			temp = temp->left;
		}
		return temp;
	}

	Node * temp = root;
	Node * succ = NULL;
	while(temp!=NULL){

		if(target->key < temp->key){
			succ = temp;
			temp = temp->left;
		}
		else if(target->key > temp->key){
			temp = temp->right;
		}
		else{     //if found the target;
			break;    
		}
	}
	return succ;

}  

void printInorder(Node* root){

	if(root==NULL){
		return;
	}
	printInorder(root->left);
	cout<<root->key<<" ";
	printInorder(root->right);
}

int main(){
	Node * root = NULL;
	int arr[] = {8,3,10,1,6,14,4,7,13};

	for(int x: arr){
		root = insert(root, x);
	}
	printInorder(root);
	cout<<endl;

	Node* t1 = root->left->right->right;
	Node* t2 = root->right;

	cout<<"Inorder succ of 7 is" << InorderSuccessor(root,t1)->key <<endl;
	cout<<"Inorder succ of 10 is" << InorderSuccessor(root,t2)->key <<endl;

	return 0;
}