#include <bits/stdc++.h>
using namespace std;

struct job
{
	int id, deadline, profit;
};

bool compare(job a, job b) { return a.profit > b.profit; }

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		job a[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i].id >> a[i].deadline >> a[i].profit;
		}
		sort(a, a + n, compare);
		bool slot[n] = {false};
		int max_profit = 0, cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = min(n, a[i].deadline) - 1; j >= 0; j--)
			{
				if (slot[j] == false)
				{
					cnt++;
					slot[j] = true;
					max_profit += a[i].profit;
					break;
				}
			}
		}
		cout << cnt << " " << max_profit << endl;
	}
	return 0;
}
