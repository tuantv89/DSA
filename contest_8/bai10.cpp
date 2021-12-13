#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int ReduceTo1(ll n)
{
	if (n == 1)
		return 0;
	queue<ll> q;
	set<ll> checked;
	int ans = 0;
	q.push(n);
	checked.insert(n);
	while (!q.empty())
	{
		ans++;
		int size = q.size();
		while (size--)
		{
			int x = q.front();
			q.pop();
			int a = x - 1;
			if (a == 1)
				return ans;
			else
			{
				if (checked.find(a) == checked.end())
				{
					q.push(a);
					checked.insert(a);
				}
			}
			for (int i = 2; i * i <= x; i++)
			{
				if (x % i == 0)
				{
					if (checked.find(x / i) == checked.end())
					{
						checked.insert(x / i);
						q.push(x / i);
					}
				}
			}
		}
	}
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		cout << ReduceTo1(n) << endl;
	}
	return 0;
}
