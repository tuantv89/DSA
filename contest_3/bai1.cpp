#include <bits/stdc++.h>
using namespace std;
int a[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
void loading(int n)
{
	int ans = 0;
	for (int i = 9; i >= 0; i--)
	{
		if (n == 0)
			break;
		while (n >= a[i])
		{
			int tmp = n / a[i];
			ans += tmp;
			n -= tmp * a[i];
		}
	}
	cout << ans << endl;
}
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
		loading(n);
	}
	return 0;
}
