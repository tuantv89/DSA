#include <bits/stdc++.h>
using namespace std;
void storeNG(int arr[], int n, int NG[])
{
	stack<int> st;
	for (int i = n - 1; i >= 0; i--)
	{
		while (!st.empty() && arr[i] >= arr[st.top()])
			st.pop();
		NG[i] = st.empty() ? -1 : st.top();
		st.push(i);
	}
}
void storeRS(int arr[], int n, int RS[])
{
	stack<int> st;
	for (int i = n - 1; i >= 0; i--)
	{
		while (!st.empty() && arr[i] <= arr[st.top()])
			st.pop();
		RS[i] = st.empty() ? -1 : st.top();
		st.push(i);
	}
}
void right_smaller(int a[], int n)
{
	int NextGreater[n];
	int RightSmaller[n];
	storeNG(a, n, NextGreater);
	storeRS(a, n, RightSmaller);
	for (int i = 0; i < n; i++)
	{
		if (NextGreater[i] != -1 && RightSmaller[NextGreater[i]] != -1)
			cout << a[RightSmaller[NextGreater[i]]] << " ";
		else
			cout << -1 << " ";
	}
	cout << endl;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		right_smaller(a, n);
	}
	return 0;
}
