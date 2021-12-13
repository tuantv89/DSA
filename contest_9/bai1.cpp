#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m, a, b;
		vector<int> ke[1005];
		cin >> n >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> a >> b;
			ke[a].push_back(b);
			ke[b].push_back(a);
		}
		for (int i = 1; i <= n; i++)
		{
			// sort(ke[i].begin(),ke[i].end());
			cout << i << ": ";
			for (int j = 0; j < ke[i].size(); j++)
				cout << ke[i][j] << " ";
			cout << endl;
		}
	}
	return 0;
}
