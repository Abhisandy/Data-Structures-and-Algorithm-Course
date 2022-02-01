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


node * KreverseLL(node *&head, int k){
	node * prev = NULL;
	node * current = head;
	node * temp;

	int cnt = 1;
	while(current!=NULL and cnt<=k){
		//storing
		temp = current->next;
		//update the current
		current->next = prev;
		//update prev and current
		prev = current;   
		current =  temp;
		cnt++;
	}
	if(temp!=NULL){                    //coz temp will point to next node when update, so here we are checking
		head->next = KreverseLL(temp, k);  //wheather is it end of LinkedList or not 				
	}
	return prev;
}

int main(){

	node *head = NULL;
	insertAtHead(head, 5);
	insertAtHead(head, 4);
	insertAtHead(head, 3);
	insertAtHead(head, 2);
	insertAtHead(head, 1);
	print(head);
	node *nhead = KreverseLL(head, 3);
	print(nhead);
}
