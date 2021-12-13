#include <bits/stdc++.h>
using namespace std;
int maxx(string a, string b)
{
	for (int i = 0; i < a.length(); i++)
		if (a[i] == '5')
			a[i] = '6';
	for (int i = 0; i < b.length(); i++)
		if (b[i] == '5')
			b[i] = '6';
	return stoll(a) + stoll(b);
}
int minn(string a, string b)
{
	for (int i = 0; i < a.length(); i++)
		if (a[i] == '6')
			a[i] = '5';
	for (int i = 0; i < b.length(); i++)
		if (b[i] == '6')
			b[i] = '5';
	return stoll(a) + stoll(b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string a, b;
	cin >> a >> b;
	cout << minn(a, b) << " " << maxx(a, b);
	return 0;
}
