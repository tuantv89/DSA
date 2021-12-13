#include <bits/stdc++.h>
using namespace std;
void pre(string s)
{
	int n = s.length(), ok = 1;
	int i = n - 1;
	while (i >= 0 && s[i] == '0')
	{
		s[i] = '1';
		i--;
	}
	if (i >= 0)
	{
		s[i] = '0';
		ok = 1;
	}
	else
		ok = 0;
	if (ok == 1)
		for (int j = 0; j < n; j++)
			cout << s[j];
	else
	{
		for (int j = 0; j < n; j++)
			cout << "1";
	}
	cout << endl;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		pre(s);
	}
	return 0;
}
