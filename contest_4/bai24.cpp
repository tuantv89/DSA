#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define M 123456789
ull proceed(int n, ull k)
{
	ull temp;
	if (k == 0)
		return 1;
	temp = proceed(n, k / 2);
	if (k % 2 == 0)
		return (temp * temp) % M;
	else
		return (temp * temp % M) * n % M;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		ull n;
		cin >> n;
		cout << proceed(2, n - 1) << endl;
	}
	return 0;
}
