#include <bits/stdc++.h>
using namespace std;
//Stack implementation using Linked List
struct node{
	int data;
	struct node *next;
};

struct node *newNode(int data){
	struct node *nnode = (struct node *) malloc(sizeof(struct node));
	nnode->data = data;
	nnode->next = NULL;
}

int isEmpty(struct node* root) 
{ 
    return !root; 
} 

void push(struct node **headref, int data){

	struct node *nnode = newNode(data);
	nnode->next = *headref;
	*headref = nnode;
	cout<<data<<" pushed to stack"<<endl;
}

int pop(struct node **headref){
	if(*headref == NULL)
		return INT_MIN;

    struct node *temp = *headref;
	int x = (*headref)->data;
	*headref = (*headref)->next;
	free(temp);
	return x;
}

int peek(struct node *head){
	if(head==NULL)
		return INT_MIN;

	return head->data;
}

int main()
{
    struct node* root = NULL;

    push(&root, 10);
    push(&root, 20);
    push(&root, 30);

    cout<<pop(&root)<<" popped from stack"<<endl;
    cout<<"Top element is "<<peek(root)<<endl;

    return 0;
}
