#include <bits/stdc++.h>
using namespace std;
bool is_operator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%')
		return true;
	return false;
}
string prefix_to_postfix(string s)
{
	int n = s.length();
	stack<string> st;
	for (int i = n - 1; i >= 0; i--)
	{
		if (is_operator(s[i]))
		{
			string tmp1 = st.top();
			st.pop();
			string tmp2 = st.top();
			st.pop();
			string tmp = tmp1 + tmp2 + s[i];
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
		cout << prefix_to_postfix(s) << endl;
	}
	return 0;
}
