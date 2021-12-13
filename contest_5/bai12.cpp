#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
ll P[1005][1005];
ll Pnk(int n, int k)
{
	memset(P, 0, sizeof(P));
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= min(i, k); j++)
		{
			if (j == 0)
				P[i][j] = 1;
			else
				P[i][j] = (P[i - 1][j] + (j * P[i - 1][j - 1])) % M;
		}
	}
	return P[n][k];
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		if (k > n)
			cout << 0 << endl;
		else
			cout << Pnk(n, k) << endl;
	}
	return 0;
}
