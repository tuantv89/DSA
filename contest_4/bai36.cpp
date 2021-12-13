#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull mutil_bin(string s1, string s2)
{
	ull x1 = stoull(s1, 0, 2);
	ull x2 = stoull(s2, 0, 2);
	return x1 * x2;
}
int main()
{
	int t;
	cin >> t;
	cin.ignore();
	while (t--)
	{
		string s1, s2;
		cin >> s1 >> s2;
		cout << mutil_bin(s1, s2) << endl;
	}
	return 0;
}
