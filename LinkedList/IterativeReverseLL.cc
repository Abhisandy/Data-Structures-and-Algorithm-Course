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


void reverseLL(node *&head){
	node * prev = NULL;
	node * current = head;
	node * temp;

	while(current!=NULL){
		//storing
		temp = current->next;
		//update the current
		current->next = prev;
		//update prev and current
		prev = current;   
		current =  temp;
	}
	head = prev;   //coz both current and temp will be NULL;
	return;
}

int main(){

	node *head = NULL;
	insertAtHead(head, 5);
	insertAtHead(head, 4);
	insertAtHead(head, 3);
	insertAtHead(head, 2);
	insertAtHead(head, 1);
	print(head);
	reverseLL(head);
	print(head);
}