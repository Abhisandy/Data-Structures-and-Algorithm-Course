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


node* reverseLL(node *head){
	if(head==NULL || head->next==NULL){
		return head;
	}
	node* sHead = reverseLL(head->next);
	head->next->next = head;
	head->next = NULL;
	return sHead;
}

int main(){

	node *head = NULL;
	insertAtHead(head, 5);
	insertAtHead(head, 4);
	insertAtHead(head, 3);
	insertAtHead(head, 2);
	insertAtHead(head, 1);
	print(head);
	node * sHead = reverseLL(head);
	print(sHead);
}