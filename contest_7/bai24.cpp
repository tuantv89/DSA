#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> va;
vector<pair<int, int>> vb;
void add(string a, string b)
{
	string tmp = "";
	pair<int, int> p;
	for (int i = 0; i < a.length(); i++)
	{
		if (isdigit(a[i]))
			tmp += a[i];
		if (a[i] == '*')
		{
			p.first = stoi(tmp);
			// cout<<p.first<<endl;
			tmp = "";
		}
		if (a[i] == '+' || i == a.length() - 1)
		{
			p.second = stoi(tmp);
			tmp = "";
			va.push_back(p);
		}
	}
	for (int i = 0; i < b.length(); i++)
	{
		if (isdigit(b[i]))
			tmp += b[i];
		if (b[i] == '*')
		{
			p.first = stoi(tmp);
			// cout<<p.first<<endl;
			tmp = "";
		}
		if (b[i] == '+' || i == b.length() - 1)
		{
			p.second = stoi(tmp);
			tmp = "";
			vb.push_back(p);
		}
	}
	// for(int i=0;i<va.size();i++)
	// cout<<va[i].first<<" "<<va[i].second<<endl;
	int n = va.size(), m = vb.size();
	int i = 0, j = 0;
	vector<pair<int, int>> res;
	while (i < n && j < m)
	{
		if (va[i].second > vb[j].second)
		{
			res.push_back(va[i]);
			i++;
		}
		else if (vb[j].second > va[i].second)
		{
			res.push_back(vb[j]);
			j++;
		}
		else
		{
			int x = va[i].first + vb[j].first;
			int y = va[i].second;
			res.push_back(make_pair(x, y));
			i++;
			j++;
		}
	}
	while (i < n)
	{
		res.push_back(va[i]);
		i++;
	}
	while (j < m)
	{
		res.push_back(vb[j]);
		j++;
	}
	for (int k = 0; k < res.size() - 1; k++)
	{
		cout << res[k].first << "*x^" << res[k].second << " + ";
	}
	cout << res[res.size() - 1].first << "*x^" << res[res.size() - 1].second << endl;
}
int main()
{
	int t;
	cin >> t;
	cin.ignore();
	while (t--)
	{
		va.clear();
		vb.clear();
		string a, b;
		getline(cin, a);
		getline(cin, b);
		add(a, b);
	}
	return 0;
}
