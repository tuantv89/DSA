
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll n;
vector<string> a;

void generate()
{
	for (ll i = 1; i * i * i <= n; i++)
	{
		ll temp = i * i * i;
		string tmp = to_string(temp);
		a.push_back(tmp);
	}
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		a.clear();
		cin >> n;
		generate();
		string s = to_string(n);
		string ans = "-1";
		int l = s.length();
		for (int i = a.size() - 1; i >= 0; i--)
		{
			if (ans != "-1")
				break;
			string tmp = a[i];
			// if(tmp.length()>l)
			// continue;
			int idx = 0;
			for (int j = 0; j < l; j++)
			{
				if (s[j] == tmp[idx])
					idx++;
				if (idx == tmp.length())
				{
					ans = tmp;
					break;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
