#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
	if (a.second.second == b.second.second)
		return a.first < b.first;
	return a.second.second > b.second.second;
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
		map<int, int> m, v;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			m[a[i]]++;
			if (v[a[i]] == 0)
				v[a[i]] = i;
		}
		vector<pair<int, pair<int, int>>> res;
		for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
		{
			res.push_back(make_pair(v[it->first], make_pair(it->first, it->second)));
		}
		sort(res.begin(), res.end(), cmp);
		for (int i = 0; i < res.size(); i++)
		{
			pair<int, int> tmp = res[i].second;
			while (tmp.second--)
				cout << tmp.first << " ";
		}
		cout << endl;
	}
	return 0;
}
