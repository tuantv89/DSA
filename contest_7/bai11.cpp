#include <bits/stdc++.h>
using namespace std;
int prec(char c)
{
	if (c == '+' || c == '-')
		return 1;
	if (c == '*' || c == '/' || c == '%')
		return 2;
	if (c == '^')
		return 3;
	return -1;
}
void infix_to_postfix(string s)
{
	int n = s.length();
	stack<char> st;
	string ans = "";
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '(')
			st.push(s[i]);
		else if ((tolower(s[i])) >= 'a' && (tolower(s[i])) <= 'z')
			ans += s[i];
		else if (s[i] == ')')
		{
			while (!st.empty() && st.top() != '(')
			{
				char c = st.top();
				st.pop();
				ans += c;
			}
			if (st.top() == '(')
				st.pop();
		}
		else
		{
			while (!st.empty() && prec(s[i]) <= prec(st.top()))
			{
				char c = st.top();
				st.pop();
				ans += c;
			}
			st.push(s[i]);
		}
	}
	while (!st.empty() && st.top() != '(')
	{
		char c = st.top();
		st.pop();
		ans += c;
	}
	cout << ans << endl;
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
		infix_to_postfix(s);
	}
	return 0;
}
