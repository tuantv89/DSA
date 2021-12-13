#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll result[505];
bool check[505];
void init()
{
	int dem = 0;
	queue<ll> q;
	q.push(9);
	while (dem < 500)
	{
		ll t = q.front();
		q.pop();
		for (int i = 1; i <= 500 && i <= t; i++)
			if (t % i == 0 && !check[i])
			{
				check[i] = true;
				result[i] = t;
				dem++;
			}
		q.push(t * 10);
		q.push(t * 10 + 9);
	}
}
int main()
{
	int t;
	cin >> t;
	init();
	while (t--)
	{
		int n;
		cin >> n;
		cout << result[n] << endl;
	}
	return 0;
}
