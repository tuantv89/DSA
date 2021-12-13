#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<pair<int, int>> ListEdge;
	int n;
	cin >> n;
	cin.ignore();
	for (int i = 1; i <= n; i++)
	{
		string s;
		getline(cin, s);
		for (int j = 0; j < s.length(); j++)
		{
			if (s[j] >= '1' && s[j] <= '9')
			{
				string tmp = "";
				while (isdigit(s[j]) && j < s.length())
				{
					tmp = tmp + string(1, s[j]);
					j++;
				}
				if (i < stoi(tmp))
					ListEdge.push_back({i, stoi(tmp)});
			}
		}
	}
	sort(ListEdge.begin(), ListEdge.end());
	for (int i = 0; i < ListEdge.size(); i++)
		cout << ListEdge[i].first << " " << ListEdge[i].second << endl;
	return 0;
}
