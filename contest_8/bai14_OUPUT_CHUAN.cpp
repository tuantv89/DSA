#include <bits/stdc++.h>
using namespace std;
void snt(int n)
{
	queue<string> q;
	q.push("4");
	q.push("5");
	while (n--)
	{
		string t = q.front();
		q.pop();
		q.push(t + "4");
		q.push(t + "5");
		cout << t;
		reverse(t.begin(), t.end());
		cout << t << " ";
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
		snt(n);
	}
	return 0;
}
