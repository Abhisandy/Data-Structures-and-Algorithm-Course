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


class LinkedList{
public:
	Node* head;
	Node* tail;
};


LinkedList Tree2LL(Node * root){
	LinkedList l;

	if(root==NULL){
		l.head = l.tail = NULL;
		return l;
	}

	//4 different cases
	if(root->left==NULL and root->right==NULL){
		l.head = l.tail = root;
	}
	else if(root->left!=NULL and root->right==NULL){
		LinkedList leftLL = Tree2LL(root->left);
		leftLL.tail->right = root;

		l.head = leftLL.head;
		l.tail = root;
	}
	else if(root->left==NULL and root->right!=NULL){
		LinkedList rightLL = Tree2LL(root->right);
		root->right = rightLL.head;

		l.head = root;
		l.tail = rightLL.tail;
	}
	else{
		LinkedList leftLL = Tree2LL(root->left);
		LinkedList rightLL = Tree2LL(root->right);
		leftLL.tail->right = root;
		root->right = rightLL.head;

		l.head = leftLL.head;
		l.tail = rightLL.tail;
	}
	return l;
}

int main(){
	Node * root = NULL;
	int arr[] = {8,3,10,1,6,14,4,7,13};

	for(int x: arr){
		root = insert(root, x);
	}
	//printInorder(root);
	//cout<<endl;

	LinkedList res = Tree2LL(root);
	Node * temp = res.head;
	while(temp!=NULL){
		cout<<temp->key<<" ";
		temp = temp->right;
	}


	return 0;
}