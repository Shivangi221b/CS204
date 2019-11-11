// Program to convert a skewed BST to a balanced BST
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* left, *right;
};

void storeBSTNodes(Node* root, vector<Node*> &nodes)
{
	if (root==NULL)
		return;

	storeBSTNodes(root->left, nodes);
	nodes.push_back(root);
	storeBSTNodes(root->right, nodes);
}

Node* buildTreeUtil(vector<Node*> &nodes, int start, int end)
{
	if (start > end)
		return NULL;

	int mid = (start + end)/2;
	Node *root = nodes[mid];

	root->left = buildTreeUtil(nodes, start, mid-1);
	root->right = buildTreeUtil(nodes, mid+1, end);

	return root;
}

Node* newNode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

void inOrder(Node* node)
{
	if (node == NULL)
		return;
	inOrder(node->left);
	printf("%d ", node->data);
	inOrder(node->right);
}

// Driver program
int main()
{
	/* Constructed skewed binary tree is
				10
			/
			8
			/
			7
		/
		6
		/
		5 */

	Node* root = newNode(10);
	root->left = newNode(8);
	root->left->left = newNode(7);
	root->left->left->left = newNode(6);
	root->left->left->left->left = newNode(5);

	vector<Node *> nodes;
	storeBSTNodes(root, nodes);
	int n = nodes.size();
	root = buildTreeUtil(nodes, 0, n-1);

	printf("Inorder traversal of balanced "
			"BST is : \n");
	inOrder(root);

	return 0;
}
