#include <bits/stdc++.h>
using namespace std;
#define M 102
int n, b[M], c[M][M];
int a[M];
int can, cmin, fopt;
int min_matrix()
{
	int min = c[0][0];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			if (i != j && min > c[i][j])
				min = c[i][j];
	}
	return min;
}
void init()
{
	for (int i = 1; i <= n; i++)
		b[i] = 1;
	fopt = INT_MAX;
	a[1] = 1;
	can = 0;
	cmin = min_matrix();
}
void update()
{
	int sum;
	sum = can + c[a[n]][a[1]];
	if (sum < fopt)
		fopt = sum;
}
void Try(int i)
{
	for (int j = 2; j <= n; j++)
	{
		if (b[j])
		{
			a[i] = j;
			b[j] = 0;
			can = can + c[a[i - 1]][a[i]];
			if (i == n)
				update();
			else if (can + (n - i + 1) * cmin < fopt)
				Try(i + 1);
			b[j] = 1;
			can -= c[a[i - 1]][a[i]];
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cin >> c[i][j];
	}
	init();
	Try(2);
	cout << fopt << endl;
	return 0;
}
