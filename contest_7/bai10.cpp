#include <bits/stdc++.h>
using namespace std;
string equivalent_expression(string s)
{
	stack<pair<int, int>> st;
	s = " " + s;
	for (int i = 1; i < s.length(); i++)
	{
		if (s[i] == '(' && s[i - 1] == '-')
		{
			st.push(make_pair(i, 1));
		}
		else if (s[i] == '(' && s[i - 1] == '+')
			st.push(make_pair(i, 0));
		else if (s[i] == ')')
		{
			if (!st.empty())
			{
				pair<int, int> tmp;
				tmp = st.top();
				if (tmp.second == 1)
				{
					for (int j = tmp.first + 1; j < i; j++)
					{
						if (s[j] == '+')
							s[j] = '-';
						else if (s[j] == '-')
							s[j] = '+';
					}
				}
				st.pop();
			}
		}
	}
	string ans = "";
	for (int i = 1; i < s.length(); i++)
	{
		if (s[i] != '(' && s[i] != ')')
			ans += s[i];
	}
	return ans;
}

int main()
{
	int t;
	cin >> t;
	cin.ignore();
	while (t--)
	{
		string a, b;
		cin >> a;
		cin >> b;
		string tmp = equivalent_expression(a);
		string temp = equivalent_expression(b);
		if (tmp.compare(temp) == 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
