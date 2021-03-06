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
int CountNode(node *root)
{
	if (root == NULL)
		return 0;
	return 1 + CountNode(root->left) + CountNode(root->right);
}
int depth(node *root)
{
	int d = 0;
	while (root != NULL)
	{
		d++;
		root = root->left;
	}
	return d;
}
int poww(int x, int y)
{
	int ans = 1;
	while (y--)
		ans *= x;
	return ans;
}
void LevelOrder(node *root)
{
	if (root == NULL)
		return;
	queue<node *> q;
	q.push(root);
	while (!q.empty())
	{
		node *t = q.front();
		q.pop();
		cout << t->value << " ";
		if (t->left != NULL)
			q.push(t->left);
		if (t->right != NULL)
			q.push(t->right);
	}
}
void solve()
{
	int n;
	cin >> n;
	node *root = ConstructTree(n);
	LevelOrder(root);
	cout << endl;
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
