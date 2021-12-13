#include <bits/stdc++.h>
using namespace std;
bool greedy_rearrange(int a[], int n)
{
	int fake[n];
	copy(a, a + n, fake);
	sort(fake, fake + n);
	for (int i = 0; i < n; i++)
	{
		if (!(a[i] == fake[i]) && !(a[n - 1 - i] == fake[i]))
			return false;
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		if (greedy_rearrange(a, n))
			cout << "Yes";
		else
			cout << "No";
		cout << endl;
	}
	return 0;
}
