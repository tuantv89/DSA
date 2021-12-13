#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		int p = 0, q = n - 1;
		while (p < q)
		{
			cout << a[q] << " " << a[p] << " ";
			p++;
			q--;
		}
		if (p == q)
			cout << a[p];
		cout << endl;
	}
	return 0;
}
