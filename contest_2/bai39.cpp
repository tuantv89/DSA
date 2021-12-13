#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	char s[35];
	ll n;
	scanf("%s%lld", s, &n);
	int l = strlen(s);
	if (n <= l)
		cout << s[n - 1];
	else
	{
		ll a[100];
		a[1] = l;
		int stop;
		for (int i = 2;; i++)
		{
			a[i] = a[i - 1] * 2;
			if (a[i] > n)
			{
				stop = i;
				break;
			}
		}
		while (1)
		{
			if (n <= l)
				break;
			ll p = lower_bound(a, a + stop, n) - (a + 1);
			n = n - a[p] - 1;
			if (n == 0)
				n = a[p];
		}
		cout << s[n - 1];
	}
	return 0;
}
