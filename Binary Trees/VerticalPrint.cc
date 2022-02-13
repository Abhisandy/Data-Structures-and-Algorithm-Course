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


void traverse(node * root, int d, map<int, vector<int>> &m){

	if(root==NULL){
		return;
	}
	m[d].push_back(root->data);
	traverse(root->left, d-1, m);
	traverse(root->right, d+1, m);
}

void VerticalPrint(node * root){

	map<int, vector<int>> m;
	int d = 0;

	traverse(root, d, m);

	for(auto p: m){

		int key = p.first;
		vector<int> val = p.second;

		for(auto v: val){
			cout<<v<<" ";
		}
		cout<<endl;
	}
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
	VerticalPrint(root);
	

	return 0;
}