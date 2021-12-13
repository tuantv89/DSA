#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int find(int n, ll k)
{
	if (k == 1)
		return 1;
	if (k == pow(2, n - 1))
		return n;
	if (k < pow(2, n - 1))
		return find(n - 1, k);
	return find(n - 1, k - pow(2, n - 1));
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		ll k;
		cin >> n >> k;
		cout << find(n, k) << endl;
	}
	return 0;
}
