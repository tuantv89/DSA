#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		queue<int> q;
		while (n--)
		{
			int x;
			cin >> x;
			if (x == 1)
				cout << q.size() << endl;
			if (x == 2)
			{
				if (q.empty())
					cout << "YES" << endl;
				else
					cout << "NO" << endl;
			}
			if (x == 3)
			{
				int tmp;
				cin >> tmp;
				q.push(tmp);
			}
			if (x == 4)
			{
				if (!q.empty())
					q.pop();
			}
			if (x == 5)
			{
				if (!q.empty())
					cout << q.front() << endl;
				else
					cout << "-1" << endl;
			}
			if (x == 6)
			{
				if (!q.empty())
					cout << q.back() << endl;
				else
					cout << -1 << endl;
			}
		}
	}
	return 0;
}
