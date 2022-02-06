#include<bits/stdc++.h>

using namespace std;




class node{

public:
	int data;
	node * left;
	node * right;

	node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};

node *BuildTree(){

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

	queue<node *> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){

		node * temp = q.front();
		if(temp==NULL){
			cout<<endl;
			q.pop();
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			q.pop();
			cout<<temp->data<<" ";
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

class HDPair{
public:
	int height;
	int diameter;
};

HDPair OptDiameter(node * root){

	HDPair p;
	if(root==NULL){
		p.height = p.diameter = 0;
		return p;
	}

	HDPair left = OptDiameter(root->left);
	HDPair right =  OptDiameter(root->right);

	p.height = 1 + max(left.height, right.height);

	int D1 = left.height + right.height;        //if root included in Diameter
	int D2 = left.diameter;                     //Diamter in left subtree only
	int D3  = right.diameter;                   //Diameter in right Subtree only

	p.diameter = max(D1, max(D2, D3));      

	return p;             
}


int main(){

	node * root = BuildTree();
	levelOrderPrint(root);
	cout<<"Optimised Diameter of Tree = "<< OptDiameter(root).diameter;
	return 0;
}