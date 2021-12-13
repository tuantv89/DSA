#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		vector<int> v(n);
		for (int i = 0; i < n; i++)
			v[i] = i + 1;
		int p = 0;
		while (v.size() != 1)
		{
			p = (p + m) % v.size();
			v.erase(v.begin() + p);
		}
		cout << v[0] << endl;
	}
	return 0;
}
