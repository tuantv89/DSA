#include <bits/stdc++.h>
using namespace std;
vector<int> x(11);
vector<vector<int>> v;
int a[11][11];
int n, k;
bool check[11] = {false};
bool check_tong()
{
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		cnt += a[i][x[i]];
	return (cnt == k);
}
void Try(int i)
{
	for (int j = 1; j <= n; j++)
	{
		if (check[j] == false)
		{
			x[i] = j;
			check[j] = true;
			if (i == n)
			{
				if (check_tong())
					v.push_back(x);
			}
			else
				Try(i + 1);
			check[j] = false;
		}
	}
}
int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	}
	Try(1);
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 1; j <= n; j++)
			cout << v[i][j] << " ";
		cout << endl;
	}
	return 0;
}
