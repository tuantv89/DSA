#include <bits/stdc++.h>
using namespace std;
int Count(string s, int x1, int x2, int val)
{
	int dem = 0;
	for (int i = x1 + 1; i < x2; i++)
	{
		if (s[i] - '0' == val)
			dem++;
	}
	return dem;
}
int cnt(string s)
{
	int dem = 0;
	for (int i = 0; i < s.length(); i++)
	{
		int tmp = -1;
		for (int j = i + 1; j < s.length(); j++)
		{

			if (s[j] == s[i])
			{
				tmp = j;
				if (tmp != -1)
					for (int p = i + 1; p < tmp; p++)
						if (Count(s, i, tmp, s[p] - '0') == 1)
							dem++;
			}
			if (tmp != -1)
				break;
		}
	}
	return dem / 2;
}
int main()
{
	string s;
	cin >> s;
	cout << cnt(s);
	return 0;
}
