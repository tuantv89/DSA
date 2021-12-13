#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<int> v;
	int l = 0;
	string s;
	while (cin >> s)
	{
		if (s == "push")
		{
			int n;
			cin >> n;
			v.push_back(n);
			l++;
		}
		if (s == "show")
		{
			if (v.empty())
				cout << "empty";
			else
				for (int i = 0; i < l; i++)
					cout << v[i] << " ";
			cout << endl;
		}
		if (s == "pop")
		{
			if (!v.empty())
			{
				l--;
				v.resize(l);
			}
		}
	}
	return 0;
}
