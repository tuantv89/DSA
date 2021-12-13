#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, x;
		cin >> n >> x;
		vector<int> v;
		for (int i = 0; i < n; i++)
		{
			int tmp;
			cin >> tmp;
			v.push_back(tmp);
		}
		sort(v.begin(), v.end());
		if (binary_search(v.begin(), v.end(), x))
			cout << 1 << endl;
		else
			cout << -1 << endl;
	}
	return 0;
}
