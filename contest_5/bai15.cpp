#include <bits/stdc++.h>
using namespace std;
int c[105][105][105];
int lcs(string s1, string s2, string s3, int m, int n, int p)
{
	int i, j, k;
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			for (k = 1; k <= p; k++)
				if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1])
					c[i][j][k] = c[i - 1][j - 1][k - 1] + 1;
				else
					c[i][j][k] = max(max(c[i - 1][j][k], c[i][j - 1][k]), c[i][j][k - 1]);
		}
	}
	return c[m][n][p];
}
int main()
{
	int t, m, n, p;
	string s1, s2, s3;
	cin >> t;
	while (t--)
	{
		cin >> m >> n >> p;
		cin >> s1 >> s2 >> s3;
		cout << lcs(s1, s2, s3, m, n, p) << endl;
	}
	return 0;
}
