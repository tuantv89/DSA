#include <bits/stdc++.h>
using namespace std;
bool cmp(string a, string b)
{
	if (a.length() == b.length())
		return a < b;
	return a.length() < b.length();
}
void snt(int n)
{
	queue<string> q;
	vector<string> res;
	q.push("44");
	q.push("55");
	while (res.size() < n)
	{
		string t = q.front();
		q.pop();
		res.push_back(t);
		q.push("4" + t + "4");
		q.push("5" + t + "5");
	}
	sort(res.begin(), res.end(), cmp);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
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
