#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<string> vs;
	string s;
	map<string, int> m;
	while (cin >> s)
	{
		m[s]++;
		auto it = find(vs.begin(), vs.end(), s);
		if (it == vs.end())
			vs.push_back(s);
	}
	sort(vs.begin(), vs.end());
	cout << vs.size() << endl;
	for (int i = 0; i < vs.size(); i++)
	{
		cout << vs[i] << " " << m[vs[i]] << endl;
	}
}
