#include <bits/stdc++.h>
using namespace std;
bool is_operator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%')
		return true;
	return false;
}
string postfix_to_prefix(string s)
{
	int n = s.length();
	stack<string> st;
	for (int i = 0; i < n; i++)
	{
		if (is_operator(s[i]))
		{
			string tmp1 = st.top();
			st.pop();
			string tmp2 = st.top();
			st.pop();
			string tmp = s[i] + tmp2 + tmp1;
			st.push(tmp);
		}
		else
		{
			st.push(string(1, s[i]));
		}
	}
	return st.top();
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		cout << postfix_to_prefix(s) << endl;
	}
	return 0;
}
