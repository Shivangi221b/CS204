#include <bits/stdc++.h>
using namespace std;

struct node{
	int key;
	struct node* left;
	struct node* right;
};

struct node* newNode(int key){
	struct node* nnode = (struct node*) malloc(sizeof(struct node));
	nnode->key = key;
	nnode->left = NULL;
	nnode->right = NULL;
}

void insert(struct node* temp, int key)
{
    queue<struct node*> q;
    q.push(temp);

    while (!q.empty()) {
    struct node* temp = q.front();
    q.pop();

    if(!temp->left){
        temp->left = newNode(key);
        break;
    }

    else
        q.push(temp->left);

    if(!temp->right){
        temp->right = newNode(key);
        break;
    }

    else
        q.push(temp->right);
    }
}

void inOrder(struct node* temp) 
{ 
    if (!temp) 
        return; 
  
    inOrder(temp->left); 
    cout << temp->key << " "; 
    inOrder(temp->right); 
} 

int main()
{
    struct node* root = newNode(10);
    root->left = newNode(11);
    root->left->left = newNode(7);
    root->right = newNode(9);
    root->right->left = newNode(15);
    root->right->right = newNode(8);

    cout << "Inorder traversal before insertion:";
    inOrder(root);

    int key = 12;
    insert(root, key);

    cout << endl;
    cout << "Inorder traversal after insertion:";
    inOrder(root);

    return 0;
}
