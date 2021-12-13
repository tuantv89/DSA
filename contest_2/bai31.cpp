#include <bits/stdc++.h>
using namespace std;
int m, n, k;
string dict[105];
bool check[5][5];
char c[5][5];
vector<string> str;
bool ok(string &x)
{

	for (int i = 0; i < k; i++)
		if (x.compare(dict[i]) == 0)
			return true;
	return false;
}
void Try(int a, int b, string &x)
{
	check[a][b] = false;
	x = x + c[a][b];
	if (ok(x))
		str.push_back(x);
	for (int i = a - 1; i <= a + 1 && i < m; i++)
		for (int j = b - 1; j <= b + 1 && j < n; j++)
			if (i >= 0 && j >= 0 && check[i][j])
				Try(i, j, x);
	x.erase(x.length() - 1);
	check[a][b] = true;
}
void handing()
{
	str.clear();
	cin >> k >> m >> n;
	for (int i = 0; i < k; i++)
		cin >> dict[i];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			check[i][j] = true;
			cin >> c[i][j];
		}
	}
	string res = "";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			Try(i, j, res);
	}
	if (str.size() == 0)
		cout << "-1";
	else
	{
		for (int i = 0; i < str.size(); i++)
		{
			cout << str[i] << " ";
		}
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		handing();
	}
	return 0;
}
