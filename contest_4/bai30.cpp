#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define M 1000000007
struct matrix
{
	ll m[2][2];
};
matrix operator*(matrix a, matrix b)
{
	matrix ans;
	for (int i = 0; i <= 1; i++)
	{
		for (int j = 0; j <= 1; j++)
		{
			ans.m[i][j] = 0;
			for (int t = 0; t <= 1; t++)
				ans.m[i][j] = (ans.m[i][j] + (a.m[i][t] * b.m[t][j]) % M) % M;
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
		ll n;
		cin >> n;
		matrix a;
		a.m[0][0] = 0;
		a.m[0][1] = 1;
		a.m[1][0] = 1;
		a.m[1][1] = 1;
		matrix res;
		res = poww(a, n - 1);
		cout << res.m[1][1] << endl;
	}
	return 0;
}
