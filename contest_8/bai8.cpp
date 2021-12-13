#include <bits/stdc++.h>
using namespace std;
int mod(string s, int n)
{
	int r = 0;
	for (int i = 0; i < s.length(); i++)
	{
		r = r * 10 + (s[i] - '0');
		r %= n;
	}
	return r;
}
string minBDN(int n)
{
	queue<string> q;
	q.push("1");
	set<int> vis;
	while (!q.empty())
	{
		string tmp = q.front();
		q.pop();
		int m = mod(tmp, n);
		if (m == 0)
			return tmp;
		else if (vis.find(m) == vis.end())
		{
			vis.insert(m);
			q.push(tmp + "0");
			q.push(tmp + "1");
		}
	}
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout << minBDN(n) << endl;
	}
	return 0;
}
