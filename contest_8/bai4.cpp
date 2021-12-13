#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void loading(string s, int k)
{
	if (k >= s.length())
	{
		cout << 0 << endl;
		return;
	}
	ll count[26] = {0};
	for (int i = 0; i < s.length(); i++)
		count[s[i] - 'A']++;
	priority_queue<ll> pq;
	for (int i = 0; i < 26; i++)
		pq.push(count[i]);
	while (k--)
	{
		ll temp = pq.top();
		pq.pop();
		temp--;
		pq.push(temp);
	}
	ll ans = 0;
	while (!pq.empty())
	{
		ll temp = pq.top();
		ans += temp * temp;
		pq.pop();
	}
	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int k;
		cin >> k;
		string s;
		cin >> s;
		loading(s, k);
	}
	return 0;
}
