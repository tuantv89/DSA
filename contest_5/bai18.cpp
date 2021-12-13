#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> Pair;
bool compare(Pair a, Pair b)
{
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}
int lps(Pair a[], int n)
{
	sort(a, a + n, compare);
	int temp = 0;
	int ans = 1;
	for (int i = 1; i < n; i++)
	{
		if (a[i].first > a[temp].second)
		{
			temp = i;
			ans++;
		}
	}
	return ans;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		Pair a[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i].first >> a[i].second;
		}
		cout << lps(a, n) << endl;
	}
	return 0;
}
