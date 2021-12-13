#include <bits/stdc++.h>
using namespace std;
int pr[205], n, s, dem = 0;
vector<vector<int>> res;
void init()
{
	for (int i = 0; i <= 200; i++)
		pr[i] = 1;
	pr[0] = 0;
	pr[1] = 0;
	for (int i = 2; i <= 200; i++)
	{
		if (pr[i])
		{
			for (int j = i * 2; j <= 200; j += i)
				pr[j] = 0;
		}
	}
}
vector<int> tmp;
int size;
int a[15];
void Try(int i)
{
	for (int j = a[i - 1] + 1; j <= size - n + i; j++)
	{
		a[i] = j;
		if (i == n)
		{
			vector<int> temp;
			int sum = 0;
			for (int t = 0; t < n; t++)
			{
				temp.push_back(tmp[a[t + 1]]);
				sum += tmp[a[t + 1]];
			}
			if (sum == s)
			{
				dem++;
				res.push_back(temp);
			}
		}
		else
			Try(i + 1);
	}
}
int main()
{
	int t;
	cin >> t;
	init();
	while (t--)
	{
		a[0] = 0;
		dem = 0;
		res.clear();
		tmp.clear();
		int p;
		cin >> n >> p >> s;
		tmp.push_back(-1);
		for (int i = p; i < s; i++)
		{
			if (pr[i])
				tmp.push_back(i);
		}
		size = tmp.size() - 1;
		Try(1);
		cout << dem << endl;
		for (int i = 0; i < res.size(); i++)
		{
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}
	}
	return 0;
}
