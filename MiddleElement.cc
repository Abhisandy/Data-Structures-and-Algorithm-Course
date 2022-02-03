#include<bits/stdc++.h>
using namespace std;


class node{
public:
	int data;
	node* next;

	node(int data){
		this->data = data;
		next = NULL;
	}
};

int getMid(node *head){
    //Complete this function to return data middle node
    node * a = head;
    node * b = head;
    while(b->next!=NULL and a->next!=NULL and a->next->next != NULL){
        b = b->next;
        a = a->next->next;
    }
    return b->data;
}