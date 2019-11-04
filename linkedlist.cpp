#include <bits/stdc++.h>
using namespace std;
/*
IMPLEMENTATION OF LINKED LISTS AS IN 2nd LAB SESSION
Create a linked list where each node contains x and y coordinates of a point. Implement the
following functions:

1. AddFirst(a,b)
This function adds a point containing ‘a’ as x-coordinate and ‘b’ as ycoordinate at the start of the linked list.

2. DelFirst()
This function deletes the first element in the linked list.
If it is not in the list or list is empty, print -1

3. Del (a,b)
This function deletes the node with point containing ‘a’ as x-coordinate and ‘b’ as ycoordinate.
If it is not in the list or list is empty, print -1

4. Search(d)
This function gives all the points that are present at atmost ‘d’ distance (Euclidean)
from the origin.
If such points exist, print the number of such points.
Else print -1

5. Search(a,b)
This function prints True, if there exists a point with ‘a’ as x-coordinate and ‘b’ as ycoordinate in the linked list.
Else it prints False

6. Length()
This function prints the length of the linked list, i.e., the number of nodes present in
the list.
*/

struct point{
    long long int x,y;
};

struct Node{
    struct point p;
    struct Node* next;
};

void AddFirst(Node** head_ref,long long int x1,long long int y1){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->p.x=x1;
    newNode->p.y=y1;
    newNode->next = *head_ref;
    *head_ref= newNode;
    return;
}

void DelFirst(Node** head_ref){
    struct Node* temp= *head_ref;
    if(temp==NULL){
        cout<< -1;
        return;
    }

    else{

        *head_ref= temp->next;
        free(temp);
        return;
    }
    
}

void Del(Node** head_ref, long long int x1, long long int y1){
    struct Node* temp= *head_ref;
    struct Node* prev;

    while(temp!=NULL){
        if(temp->p.x==x1 && temp->p.y==y1){
            if(temp==*head_ref){
                *head_ref=temp->next;
                free(temp);
                return;
            }
            else{
                prev->next= temp->next;
                free(temp);
                return;
            }
        }

        else
        {
            prev=temp;
            temp=temp->next;
        }

    }

    cout<< -1;
}

void Search1(Node** head_ref, long double d){
    struct Node* temp= *head_ref;
    int count=0;

    while(temp!=NULL){
        if(sqrt(pow(temp->p.x, 2)+pow(temp->p.y, 2))<= d)
            count++;

        temp=temp->next;
    }
    
    if(count!=0)
    	cout<< count;
    	
    else 
	cout << -1;
}

void Search2(Node** head_ref, long long int x1, long long int y1){

    struct Node* temp= *head_ref;

    while(temp!=NULL){
        if(temp->p.x==x1 && temp->p.y==y1){
            cout<< "True";
            return;
        }

        temp=temp->next;
    }

    cout<< "False";
    return;
}

void Length(Node** head_ref){

    struct Node* temp= *head_ref;
    int c=0;

    while(temp!=NULL){
        c++;
        temp=temp->next;
    }
    cout<< c;
}



int main(){
    struct Node* head_ref=NULL;
    long long int x;
    cin>>x;
    for(int i=0; i<x; i++){
        int n;
        cin>>n;

        switch(n){
            case 1:
                long long int x,y;
                cin>>x;
                cin>>y;
                AddFirst(&head_ref,x,y);
                break;

            case 2:
                DelFirst(&head_ref);
                break;

            case 3:
                long long int a,b;
                cin>>a;
                cin>>b;
                Del(&head_ref,a,b);
                break;

            case 4:
                long double d;
                cin>>d;
                Search1(&head_ref,d);
                break;

            case 5:
                long long int c,e;
                cin>>c;
                cin>>e;
                Search2(&head_ref,c,e);
                break;

            case 6:
                Length(&head_ref);
                break;

        }
    }

return 0;
}