#include <bits/stdc++.h>
using namespace std;
void distance(string a, string b, vector<string> &v)
{
	unordered_set<string> s(v.begin(), v.end());
	unordered_set<string>::const_iterator it = s.find(b);
	if (it == s.end())
		return;
	unordered_map<string, int> m;
	m[a] = 1;
	queue<string> q;
	q.push(a);
	while (!q.empty())
	{
		string t = q.front();
		q.pop();
		for (int i = 0; i < t.length(); i++)
		{
			string tmp = t;
			for (char c = 'A'; c <= 'Z'; c++)
			{
				tmp[i] = c;
				if (s.count(tmp) && tmp == b)
				{
					cout << m[t] + 1 << endl;
					return;
				}
				if (s.count(tmp) && !m.count(tmp))
				{
					q.push(tmp);
					m[tmp] = m[t] + 1;
				}
			}
		}
	}
	// return 0;
}
vector<string> vs;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		vs.clear();
		int n;
		string a, b;
		cin >> n >> a >> b;
		for (int i = 0; i < n; i++)
		{
			string x;
			cin >> x;
			vs.push_back(x);
		}
		distance(a, b, vs);
	}
}
