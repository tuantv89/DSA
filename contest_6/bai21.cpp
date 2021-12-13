#include <bits/stdc++.h>
using namespace std;
bool compare(pair<int, int> &p1, pair<int, int> &p2)
{
	if (p1.second == p2.second)
		return p1 < p2;
	return p1.second > p2.second;
}
int main()
{
	int t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		int a[n];
		map<int, int> h;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			h[a[i]]++;
		}
		map<int, int>::iterator it;
		int i = 0;
		pair<int, int> p[10005];
		for (it = h.begin(); it != h.end(); it++)
		{
			p[i++] = make_pair(it->first, it->second);
		}
		sort(p, p + i, compare);
		for (int j = 0; j < i; j++)
		{
			while (p[j].second--)
				cout << p[j].first << " ";
		}
		cout << endl;
	}
	return 0;
}
