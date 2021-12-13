#include <bits/stdc++.h>
using namespace std;
bool cmp(int x, int y) { return x > y; }
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n, cmp);
		int t = 0;
		for (int i = 1; i <= k; i++)
		{
			cout << a[t] << " ";
			t++;
		}
		cout << endl;
	}
	return 0;
}
