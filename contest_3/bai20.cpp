#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mini_swap(string s)
{
	int n = s.length();
	int p = 0, cnt = 0, ans = 0;
	vector<int> pos;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '[')
			pos.push_back(i);
	}
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '[')
		{
			cnt++;
			p++;
		}
		else
			cnt--;
		if (cnt < 0)
		{
			ans += pos[p] - i;
			swap(s[i], s[pos[p]]);
			cnt = 1;
			p++;
		}
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	cin.ignore();
	while (t--)
	{
		string s;
		cin >> s;
		cout << mini_swap(s) << endl;
	}
	return 0;
}
