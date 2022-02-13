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

int max_level = 0;
void leftViewUntil(vector<int> &v, node * root, int level){

	if(root==NULL){
		return;
	}
	if(max_level<level){
		v.push_back(root->data);
		max_level = level; 
	}

	leftViewUntil(v, root->left, level + 1);
	leftViewUntil(v, root->right, level + 1);
}

vector<int> leftView(node * root){

    vector<int> res;
    max_level = 0;
    leftViewUntil(res, root, 1);  //res, root, level(root)
    return res;
}


int main(){

	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->right = new node(4);
	root->left->right->right = new node(5);
	root->right->right = new node(6);
	
	levelOrderPrint(root);
	cout<<endl;
	
	auto res = leftView(root);
	for(int p: res){
		cout<<p<<" ";
	}
	

	return 0;
}