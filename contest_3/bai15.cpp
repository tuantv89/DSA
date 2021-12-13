#include <bits/stdc++.h>
using namespace std;

int sinh_ton(int n, int s, int m)
{
	if ((s > 6 && 6 * n < 7 * m) || (n < m))
		return -1;
	int days = (s * m) / n;
	if ((s * m) % n != 0)
		days++;
	return days;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n, s, m;
		cin >> n >> s >> m;
		cout << sinh_ton(n, s, m) << endl;
	}
	return 0;
}
