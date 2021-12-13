#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n;
	cin >> n;
	ll a[n], b[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	sort(a, a + n);
	sort(b, b + n);
	int ok = 1;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > b[i])
		{
			ok = 0;
			break;
		}
	}
	if (ok == 0)
		cout << "NO";
	else
		cout << "YES";
	return 0;
}
