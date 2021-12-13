#include <bits/stdc++.h>
using namespace std;
bool check1(string x)
{
	int len = x.length();
	for (int i = 1; i < len; i++)
	{
		if ((x[i] - '0') > (x[i - 1] - '0'))
		{
			return false;
			break;
		}
	}
	return true;
}
bool check2(string x)
{
	int len = x.length();
	for (int i = 1; i < len; i++)
	{
		if ((x[i] - '0') < (x[i - 1] - '0'))
		{
			return false;
			break;
		}
	}
	return true;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string x;
		cin >> x;
		if (check1(x) || check2(x))
			cout << "YES";
		else
			cout << "NO";
		cout << endl;
	}
	return 0;
}
