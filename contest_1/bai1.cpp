#include <bits/stdc++.h>
using namespace std;
void in(string s)
{
	int n = s.length(), ok = 1;
	int i = n - 1;
	while (s[i] == '1')
	{
		s[i] = '0';
		i--;
	}
	if (i >= 0)
		s[i] = '1';
	else
		ok = 0;
	if (ok == 1)
		for (int j = 0; j < n; j++)
			cout << s[j];
	else
	{
		for (int j = 0; j < n; j++)
			cout << "0";
	}
	cout << endl;
}
int main()
{
	int t;
	cin >> t;
	cin.ignore();
	while (t--)
	{
		string s;
		cin >> s;
		in(s);
	}
	return 0;
}
