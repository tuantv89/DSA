#include <bits/stdc++.h>
using namespace std;
struct node
{
	int value;
	node *left, *right;
	node(int x)
	{
		value = x;
		left = NULL;
		right = NULL;
	}
};
/*node* ConstructTree(int n)
{
	node *root=NULL;
	queue<node *> q;
	for(;n>0;n--)
	{
		int a,b;
		char c;
		cin>>a>>b>>c;
		if(!root)
		{
			root=new node(a);
			q.push(root);
		}
		node *t=q.front(); q.pop();
		if(c=='L')
		{
			t->left=new node(b);
			q.push(t->left);
		}
		else
		if(c=='R')
		{
			t->right=new node(b);
			q.push(t->right);
		}
		n--;
		if(!n) break;
		cin>>a>>b>>c;
		if(c=='R')
		{
			t->right=new node(b);
			q.push(t->right);
		}
		else
		if(c=='L')
		{
			t->left=new node(b);
			q.push(t->left);
		}
	}
	return root;
}*/
node *ConstructTree(int n)
{
	map<int, node *> m;
	node *root = NULL;
	while (n--)
	{
		int a, b;
		char c;
		cin >> a >> b >> c;
		node *cha;
		if (m.find(a) == m.end())
		{
			cha = new node(a);
			m[a] = cha;
			if (root == NULL)
				root = cha;
		}
		else
			cha = m[a];
		node *con = new node(b);
		if (c == 'L')
			cha->left = con;
		else if (c == 'R')
			cha->right = con;
		m[b] = con;
	}
	return root;
}
bool isFullTree(node *root)
{
	if (root == NULL)
		return true;
	if (!root->left && !root->right)
		return true;
	if ((root->left) && (root->right))
	{
		return (isFullTree(root->left) && isFullTree(root->right));
	}
	return false;
}

void solve()
{
	int n;
	cin >> n;
	node *root = ConstructTree(n);
	if (isFullTree(root))
		cout << 1 << endl;
	else
		cout << 0 << endl;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
