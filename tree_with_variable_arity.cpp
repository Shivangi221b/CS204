#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *child,*sibling;
};

void preorder(struct node* p)
{
    if(p==NULL)return;
    cout<<p->data<<" ";
    preorder(p->child);

    preorder(p->sibling);
}
struct node* search(struct node* root,int data)
{
    if(root==NULL)
        return NULL;
    if(data==root->data)
        return root;
    struct node* t = search(root->child,data);
    if(t==NULL)
         t = search(root->sibling,data);
    return t;

}

struct node* createNode(int data)
{
    struct node* newnode= (struct node*)malloc(sizeof(struct node));
    newnode->child=NULL;
    newnode->sibling=NULL;
    newnode->data=data;
    return newnode;
}

struct node* createTree(struct node* root,int data[])
{
    struct node * newnode = search(root,data[0]);

    if(newnode==NULL)
    {
        newnode= createNode(data[0]);
    }

    struct node* parent=newnode;
    int j;
    for(j=0;j<data[1];j++)
    {
        if(j==0)
        {
             parent->child=createNode(data[j+2]);
             parent = parent->child;
        }
        else
        {
            parent->sibling=createNode(data[j+2]);
            parent = parent->sibling;
        }

    }

    if(root==NULL)
            root = newnode;
    return root;


}
int main()
{
    int row = 3;

    //1st element in each row is node Value, 2nd - no of child, 3rd....=>value of child
    int data[3][5]={{1,3,2,3,4},
                    {2,2,5,6,0},
                    {3,3,8,9,10}};
    int i,j;
    struct node* root=NULL;
    for(i=0;i<row;i++)
    {
        root = createTree(root,data[i]);
    }

    preorder(root);
}
