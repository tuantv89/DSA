#include <bits/stdc++.h>
using namespace std;

struct activity
{
	int start, finish;
};

bool cmp(activity a, activity b)
{
	return a.finish < b.finish;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		activity a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i].start;
		for (int i = 0; i < n; i++)
			cin >> a[i].finish;
		sort(a, a + n, cmp);
		int ans = 1, j = 0;
		for (int i = 1; i < n; i++)
		{
			if (a[i].start >= a[j].finish)
			{
				ans++;
				j = i;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
