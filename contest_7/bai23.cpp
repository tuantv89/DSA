// 3[b2[ca]]
#include <bits/stdc++.h>
using namespace std;
string encode(string s)
{
	stack<int> st1;
	stack<char> st2;
	string tmp = "", res = "";
	for (int i = 0; i < s.length(); i++)
	{
		int cnt = 0;
		if (isdigit(s[i]))
		{
			while (isdigit(s[i]))
			{
				cnt = cnt * 10 + s[i] - '0';
				i++;
			}
			i--;
			st1.push(cnt);
		}
		else if (s[i] == ']')
		{
			tmp = "";
			cnt = 0;
			if (!st1.empty())
			{
				cnt = st1.top();
				st1.pop();
			}
			while (!st2.empty() && st2.top() != '[')
			{
				tmp = st2.top() + tmp;
				st2.pop();
			}
			if (!st2.empty() && st2.top() == '[')
				st2.pop();
			for (int j = 1; j <= cnt; j++)
				res = res + tmp;
			for (int j = 0; j < res.length(); j++)
				st2.push(res[j]);
			res = "";
		}
		else if (s[i] == '[')
		{
			if (isdigit(s[i - 1]))
				st2.push(s[i]);
			else
			{
				st2.push(s[i]);
				st1.push(1);
			}
		}
		else
			st2.push(s[i]);
	}
	while (!st2.empty())
	{
		res = st2.top() + res;
		st2.pop();
	}
	return res;
}
int main()
{
	int t;
	cin >> t;
	cin.ignore();
	while (t--)
	{
		string s;
		cin >> s;
		cout << encode(s) << endl;
	}
	return 0;
}
