#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
typedef unsigned long long ull;
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
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		ull sum = 0;
		sort(a, a + n);
		for (int i = 0; i < n; i++)
		{
			sum = (sum % M + (a[i] * i) % M) % M;
		}
		cout << sum << endl;
	}
	return 0;
}
