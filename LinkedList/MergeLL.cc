#include<bits/stdc++.h>

using namespace std;

class node{
public:
		int data;
		node *next;

		node(int data){
			this->data = data;
			next = NULL;
		}
};

void insertAtHead(node *&head, int data){
	if(head==NULL){
		head = new node(data);
		return;
	}
	node *n = new node(data);
	n->next = head;
	head = n;
}

void print(node *head){
	while(head != NULL){
		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<endl;
}

node * Merge(node * a, node * b){
	if(a == NULL){
		return b;
	}
	if(b == NULL){
		return a;
	}

	node * c;
	if(a->data < b->data){
		c = a;
		c->next = Merge(a->next, b);
	}
	else{
		c = b;
		c->next = Merge(a, b->next);
	}
	return c;
}



int main(){

	node *a = NULL;
	insertAtHead(a, 9);
	insertAtHead(a, 7);
	insertAtHead(a, 5);
	insertAtHead(a, 3);

	node *b = NULL;
	insertAtHead(b, 6);
	insertAtHead(b, 4);
	insertAtHead(b, 2);
	insertAtHead(b, 2);

	print(a);
	print(b);
	node * c = Merge(a, b);
	print(c); 
	
}