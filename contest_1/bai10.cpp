#include <bits/stdc++.h>
using namespace std;
char XOR_OF(char a, char b)
{
	return (a == b) ? '0' : '1';
}

void binToGray(string str)
{
	string res = "";
	res += str[0];
	for (int i = 1; i < str.length(); i++)
		res += XOR_OF(str[i - 1], str[i]);

	cout << res;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string bin;
		cin >> bin;
		binToGray(bin);
		cout << endl;
	}
	return 0;
}
