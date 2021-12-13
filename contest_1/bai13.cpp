#include <bits/stdc++.h>
using namespace std;
int n, k, d = 0;
vector<vector<int>> v;
vector<int> x;
void update()
{
	v.push_back(x);
	d++;
}
void in()
{
	for (int i = v.size() - 1; i >= 0; i--)
	{
		for (int j = 0; j < v.at(i).size(); j++)
		{
			if (v.at(i).at(j) == 1)
				cout << "A";
			else
				cout << "B";
		}
		cout << endl;
	}
}
bool check()
{
	int dem = 0, t = 0;
	for (int i = 0; i < n; i++)
	{
		if (x.at(i) == 1)
			t++;
		else
			t = 0;
		if (t > k)
			return false;
		else if (t == k)
			dem++;
	}
	return (dem == 1);
}
void Try(int i)
{
	for (int j = 0; j <= 1; j++)
	{
		x.at(i) = j;
		if (i == n - 1)
		{
			if (check())
				update();
		}
		else
			Try(i + 1);
	}
}
int main()
{
	cin >> n >> k;
	x.resize(n);
	Try(0);
	cout << d << endl;
	in();
	return 0;
}
