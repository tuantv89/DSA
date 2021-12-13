#include <bits/stdc++.h>
using namespace std;
bool ok(string s)
{
	stack<char> st;
	int n = s.length();
	for (int i = 0; i < n; i++)
	{
		if (s[i] == ')')
		{
			char top = st.top();
			st.pop();
			bool flag = true;
			while (top != '(')
			{
				if (top == '+' || top == '-' || top == '*' || top == '/' || top == '%')
					flag = false;
				top = st.top();
				st.pop();
			}
			if (flag == true)
				return true;
		}
		else
			st.push(s[i]);
	}
	return false;
}
int main()
{
	int t;
	cin >> t;
	string s;
	while (t--)
	{
		cin >> s;
		if (ok(s) == true)
			cout << "Yes";
		else
			cout << "No";
		cout << endl;
	}
	return 0;
}
