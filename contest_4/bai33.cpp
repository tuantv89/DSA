#include <bits/stdc++.h>
using namespace std;
typedef long long ull;
#define M 1000000007
ull poww(ull n, ull k)
{
	// if(k==1)
	// return n;
	if (k == 0)
		return 1;
	ull temp = poww(n, k / 2);
	temp = temp * temp % M;
	if (k % 2 == 0)
		return temp;
	return temp * n % M;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		ull n;
		cin >> n;
		ull tmp = n, r = 0;
		while (tmp)
		{
			r = 10 * r + tmp % 10;
			tmp /= 10;
		}
		cout << poww(n, r) << endl;
	}
	return 0;
}
