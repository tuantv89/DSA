#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define M 1000000007
ull poww(int n, unsigned int k)
{
	ull temp;
	if (k == 0)
		return 1;
	temp = poww(n, k / 2);
	if (k % 2 == 0)
		return (temp * temp) % M;
	else
		return (temp * temp % M) * n % M;
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
		unsigned int k;
		cin >> n >> k;
		cout << poww(n, k) << endl;
	}
	return 0;
}
