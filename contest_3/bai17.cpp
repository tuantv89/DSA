#include <bits/stdc++.h>
using namespace std;

void loading(string s, int k)
{
	map<char, int> m;
	priority_queue<int> pq;
	for (int i = 0; i < s.length(); i++)
		m[s[i]]++;
	map<char, int>::iterator it;
	for (it = m.begin(); it != m.end(); it++)
	{
		pq.push(it->second);
	}
	while (k--)
	{
		int temp = pq.top();
		pq.pop();
		temp -= 1;
		pq.push(temp);
	}

	int ans = 0;
	while (!pq.empty())
	{
		int temp = pq.top();
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
