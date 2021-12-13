#include <bits/stdc++.h>
using namespace std;
struct node
{
	int val;
	node *left;
	node *right;
	node(int V)
	{
		val = V;
		left = right = NULL;
	}
};
node *insert(node *root, int val)
{
	if (root == NULL)
	{
		return new node(val);
	}
	if (val < root->val)
		root->left = insert(root->left, val);
	else
		root->right = insert(root->right, val);
	return root;
}
node *TraiNhat(node *root)
{
	node *current = root;
	while (current && current->left != NULL)
		current = current->left;
	return current;
}
node *remove(node *root, int key)
{
	if (root == NULL)
		return root;
	if (key < root->val)
		root->left = remove(root->left, key);
	else if (key > root->val)
		root->right = remove(root->right, key);
	else
	{
		if (root->left == NULL)
		{
			node *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			node *temp = root->left;
			free(root);
			return temp;
		}
		node *tmp = TraiNhat(root->right);
		root->val = tmp->val;
		root->right = remove(root->right, tmp->val);
	}
	return root;
}
void inorder(node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		cout << root->val << " ";
		inorder(root->right);
	}
}
void preorder(node *root)
{
	if (root != NULL)
	{
		cout << root->val << " ";
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(node *root)
{
	if (root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout << root->val << " ";
	}
}
int main()
{
	int x;
	node *root = NULL;
	while (cin >> x)
	{
		if (x == 1)
		{
			int y;
			cin >> y;
			root = insert(root, y);
		}
		if (x == 2)
		{
			int y;
			cin >> y;
			root = remove(root, y);
		}
		if (x == 3)
		{
			preorder(root);
			cout << endl;
		}
		if (x == 4)
		{
			inorder(root);
			cout << endl;
		}
		if (x == 5)
		{
			postorder(root);
			cout << endl;
		}
	}
	return 0;
}
