#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	stack<int> st;
	string s;
	while (t--)
	{
		cin >> s;
		if (s == "PUSH")
		{
			int n;
			cin >> n;
			st.push(n);
		}
		if (s == "POP")
		{
			if (!st.empty())
				st.pop();
		}
		if (s == "PRINT")
		{
			if (st.empty())
				cout << "NONE";
			else
				cout << st.top();
			cout << endl;
		}
	}
	return 0;
}
