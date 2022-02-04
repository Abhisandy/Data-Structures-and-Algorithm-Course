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

node * MidPoint(node * head){
	node * slow = head;
	node * fast = head->next;

	while(fast!=NULL and fast->next!=NULL){
		slow = slow->next;
		fast = fast->next->next;       //only move if fast!=NULL and fast->next!=NULL
	}
	return slow;
}

node * MergeSort(node * head){

	if(head==NULL or head->next==NULL){
		return head;
	}

	node * mid = MidPoint(head);
	node * a = head;
	node * b = mid->next;
	mid->next = NULL;         //break into 2

	a = MergeSort(a);
	b = MergeSort(b);
	return Merge(a, b);
}


int main(){

	node *head = NULL;
	insertAtHead(head, 9);
	insertAtHead(head, 7);
	insertAtHead(head, 5);
	insertAtHead(head, 3);
	insertAtHead(head, 6);
	insertAtHead(head, 4);
	insertAtHead(head, 2);
	insertAtHead(head, 2);


	print(head);
	head = MergeSort(head);
	print(head); 
	
}