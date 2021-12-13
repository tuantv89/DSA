#include <bits/stdc++.h>
using namespace std;
int tinh(int x, int y, char c)
{
	if (c == '+')
		return x + y;
	if (c == '-')
		return x - y;
	if (c == '*')
		return x * y;
	if (c == '/')
		return x / y;
	if (c == '%')
		return x % y;
}
int caculate_postfix(string s)
{
	stack<int> st;
	for (int i = 0; i < s.length(); i++)
	{
		if (isdigit(s[i]))
			st.push(s[i] - '0');
		else
		{
			int x1 = st.top();
			st.pop();
			int x2 = st.top();
			st.pop();
			int tmp = tinh(x2, x1, s[i]);
			st.push(tmp);
		}
	}
	return st.top();
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
		cout << caculate_postfix(s) << endl;
	}
	return 0;
}
