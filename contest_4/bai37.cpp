#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		ull a[n], x;
		int id = -1;
		cin >> x;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (a[i] <= x)
				id = i + 1;
		}
		cout << id << endl;
	}
	return 0;
}
