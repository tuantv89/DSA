#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	cin.ignore();
	for (int i = 1; i <= t; i++)
	{
		string s;
		getline(cin, s);
		long long ans = 1;
		int m = 0, d = 0;
		if (s.length() == 0)
		{
			cout << i << " " << 1 << endl;
			continue;
		}
		for (int j = 0; j < s.length(); j++)
		{
			if (s[j] == '[')
			{
				d++;
				if (m < d)
				{
					ans *= 2;
					m = d;
				}
			}
			else
				d--;
		}
		cout << i << " " << ans << endl;
	}
	return 0;
}
