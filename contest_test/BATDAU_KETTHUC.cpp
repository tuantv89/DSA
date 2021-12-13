#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string a;
		cin >> a;
		if (a[0] - '0' == a[a.length() - 1] - '0')
			cout << "YES";
		else
			cout << "NO";
		cout << endl;
	}
	return 0;
}
