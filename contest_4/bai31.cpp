#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define M 1000000007
struct matrix
{
	ll m[11][11];
};
int n, k;
matrix operator*(matrix a, matrix b)
{
	matrix ans;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			ans.m[i][j] = 0;
			for (int t = 1; t <= n; t++)
				ans.m[i][j] = (ans.m[i][j] + (a.m[i][t] * b.m[t][j])) % M;
		}
	}
	return ans;
}
matrix poww(matrix a, ll n)
{
	if (n == 1)
		return a;
	matrix tmp = poww(a, n / 2);
	if (n % 2 == 0)
		return tmp * tmp;
	return tmp * tmp * a;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		matrix a;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				cin >> a.m[i][j];
		}
		matrix ans = poww(a, k);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				cout << ans.m[i][j] << " ";
			cout << endl;
		}
	}
	return 0;
}
