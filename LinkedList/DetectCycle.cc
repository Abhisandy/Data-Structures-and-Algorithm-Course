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

bool containsCycle(node *head){
    
    unordered_set<node*> s;
    node* temp = head;
    while(temp!=NULL){
        
        if(s.find(temp) != s.end()){    //find cycle if same element
            return true;
        }
        
        s.insert(temp);
        temp = temp->next;
        
    }
    return false;
}