#include <bits/stdc++.h>
using namespace std;
void chuan(string &s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 'a' - 'A';
	}
}
void solve(string s)
{
	chuan(s);
	vector<string> a;
	for (int i = 0; i < s.length(); i++)
	{
		string tmp = "";
		while (s[i] != ' ' && i < s.length())
		{
			tmp += s[i];
			i++;
		}
		if (tmp != "")
		{
			int j = 0;
			while (j < tmp.length())
			{
				if (tmp[j] >= 'a' && tmp[j] <= 'z')
				{
					tmp[j] += 'A' - 'a';
					break;
				}
				else
					j++;
			}
			a.push_back(tmp);
		}
	}
	for (int i = 1; i < a.size(); i++)
	{
		if (i == a.size() - 1)
			cout << a[i];
		else
			cout << a[i] << ' ';
	}
	cout << ","
		 << " ";
	for (int i = 0; i < a[0].length(); i++)
	{
		if (a[0][i] >= 'a' && a[0][i] <= 'z')
			a[0][i] += 'A' - 'a';
	}
	cout << a[0] << endl;
}
int main()
{
	int t;
	cin >> t;
	cin.ignore();
	while (t--)
	{
		string s;
		getline(cin, s);
		solve(s);
	}
	return 0;
}
