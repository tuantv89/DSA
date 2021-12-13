#include <bits/stdc++.h>
using namespace std;
string s;
string next()
{
	int n = s.length();
	int i = n - 1;
	while (i > 0 && s[i - 1] >= s[i])
		i--;
	if (i == 0)
		return "BIGGEST";
	for (int j = n - 1; j > i - 1; j--)
	{
		if (s[j] > s[i - 1])
		{
			swap(s[j], s[i - 1]);
			break;
		}
	}
	for (int j = n - 1; i < j; i++, j--)
	{
		swap(s[i], s[j]);
	}
	return s;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int stt;
		cin >> stt;
		cin >> s;
		cout << stt << " " << next() << endl;
	}
	return 0;
}
