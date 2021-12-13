#include <bits/stdc++.h>
using namespace std;
vector<string> ans;
bool is_ok(string x)
{
	for (int i = 0; i < x.length(); i++)
	{
		if (x[i] - '0' > 5 || count(x.begin(), x.end(), x[i]) > 1)
			return false;
	}
	return true;
}
bool cmp(string x, string y)
{
	if (x.length() == y.length())
		return x < y;
	else
		return x.length() < y.length();
}
void init()
{
	queue<string> q;
	q.push("1");
	q.push("2");
	q.push("3");
	q.push("4");
	q.push("5");
	ans.push_back("0");
	while (!q.empty())
	{
		string x = q.front();
		q.pop();
		if (is_ok(x))
			ans.push_back(x);
		if (x.length() == 6)
			continue;
		for (int i = 0; i < 6; i++)
		{
			string tmp = x + to_string(i);
			q.push(tmp);
		}
	}
}
int cnt(string l, string r)
{
	int res = 0;
	for (int i = 0; i < ans.size(); i++)
	{
		if (cmp(l, ans[i]) && cmp(ans[i], r))
			res++;
		else if (ans[i] == l || ans[i] == r)
			res++;
	}
	return res;
}
int main()
{
	int t;
	cin >> t;
	init();
	while (t--)
	{
		string a, b;
		cin >> a >> b;
		cout << cnt(a, b) << endl;
	}
	return 0;
}
