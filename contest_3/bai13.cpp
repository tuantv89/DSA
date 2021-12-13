#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, pair<char, int>> a, pair<int, pair<char, int>> b)
{
	if (a.second.second == b.second.second)
		return a.first < b.first;
	return a.second.second > b.second.second;
}
void loading(string s, int d)
{
	int n = s.length();
	bool check[n] = {false};
	map<char, int> m;
	map<char, int> v;
	for (int i = 0; i < n; i++)
	{
		m[s[i]]++;
		if (v[s[i]] == 0)
			v[s[i]] = i;
	}
	v[s[0]] = 0;
	vector<pair<int, pair<char, int>>> res;
	for (map<char, int>::iterator it = m.begin(); it != m.end(); it++)
		res.push_back(make_pair(v[it->first], make_pair(it->first, it->second)));
	sort(res.begin(), res.end(), cmp);
	for (int i = 0; i < res.size(); i++)
	{
		pair<char, int> tmp = res[i].second;
		int t = 0;
		while (check[t] == true)
			t++;
		for (int j = 0; j < tmp.second; j++)
		{
			if (t + j * d >= n)
			{
				cout << "-1" << endl;
				return;
			}
			check[t + j * d] = true;
		}
	}
	cout << 1 << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	cin.ignore();
	while (t--)
	{
		int d;
		string s;
		cin >> d;
		cin >> s;
		loading(s, d);
	}
	return 0;
}
