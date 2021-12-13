#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

bool compare(int i, int j) { return i > j; }

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		ull a[n], b[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
			cin >> b[i];
		sort(a, a + n);
		sort(b, b + n, compare);
		ull result = 0;
		for (int i = 0; i < n; i++)
			result += a[i] * b[i];
		cout << result << endl;
	}
	return 0;
}
