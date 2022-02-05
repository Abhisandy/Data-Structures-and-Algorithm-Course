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

node * BuildTree(){

	int d;
	cin>>d;
	if(d==-1){
		return NULL;
	}
	node * n = new node(d);
	n->left = BuildTree();
	n->right = BuildTree();

	return n;

}


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

int main(){

	node * root = BuildTree();
	levelOrderPrint(root);

	return 0;
}