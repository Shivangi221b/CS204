#include <bits/stdc++.h>
using namespace std;

/*IMPLEMENTATION OF TREAPS
ADTs: INSERT
      SEARCH
      DELETE*/

struct TreapNod  { 
   int data;
   int priority;
   TreapNod* l, *r;
   TreapNod(int d) { //constructor
      this->data = d;
      this->priority = rand() % 100;
      this->l= this->r = nullptr;
   }
};
void rotLeft(TreapNod* &root) { 
   TreapNod* R = root->r;
   TreapNod* X = root->r->l;
   R->l = root;
   root->r= X;
   root = R;
}
void rotRight(TreapNod* &root) { 
   TreapNod* L = root->l;
   TreapNod* Y = root->l->r;
   L->r = root;
   root->l= Y;
   root = L;
}
void insertNod(TreapNod* &root, int d) { 
   if (root == nullptr) {
      root = new TreapNod(d);
      return;
   }
   if (d < root->data) {
      insertNod(root->l, d);
      if (root->l != nullptr && root->l->priority > root->priority)
      rotRight(root);
   } else {
      insertNod(root->r, d);
      if (root->r!= nullptr && root->r->priority > root->priority)
      rotLeft(root);
   }
}
bool searchNod(TreapNod* root, int key) {
   if (root == nullptr)
      return false;
   if (root->data == key)
      return true;
   if (key < root->data)
      return searchNod(root->l, key);
      return searchNod(root->r, key);
}
void deleteNod(TreapNod* &root, int key) {
   
   if (root == nullptr)
      return;
   if (key < root->data)
      deleteNod(root->l, key);
   else if (key > root->data)
      deleteNod(root->r, key);
      
   else {
      if (root->l ==nullptr && root->r == nullptr) {
         delete root;
         root = nullptr;
      }
      else if (root->l && root->r) {
         if (root->l->priority < root->r->priority) {
            rotLeft(root);
            deleteNod(root->l, key);
         } else {
            rotRight(root);
            deleteNod(root->r, key);
         }
      }
      
      else {
         TreapNod* child = (root->l)? root->l: root->r;
         TreapNod* curr = root;
         root = child;
         delete curr;
      }
   }
}

void inorder(TreapNod* root) 
{ 
    if (root) 
    { 
        inorder(root->l); 
        cout << "key: "<< root->data << " , priority: "
            << root->priority; 
        if (root->l) 
            cout << " , left child: " << root->l->data; 
        if (root->r) 
            cout << " , right child: " << root->r->data; 
        cout << endl; 
        inorder(root->r); 
    } 
} 

int main() {
   int nums[] = {1,7,6,4,3,2,8,9,10 };
   int a = sizeof(nums)/sizeof(int);
   TreapNod* root = nullptr;
   srand(time(nullptr));

   for (int n: nums)
      insertNod(root, n);

   cout << "Constructed Treap:\n\n";
   inorder(root);

   cout << "\nDeleting node 8:\n\n";
   deleteNod(root, 8);
   inorder(root);

   cout << "\nDeleting node 3:\n\n";
   deleteNod(root, 3);
   inorder(root);
   return 0;
}
