#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	string s;
	cin >> t;
	while (t--)
	{
		cin >> s;
		stack<int> st;
		for (int i = 0; i <= s.size(); i++)
		{
			if (s[i] == 'I' || i == s.size())
			{
				cout << i + 1;
				while (!st.empty())
				{
					cout << st.top();
					st.pop();
				}
			}
			else if (s[i] == 'D')
			{
				st.push(i + 1);
			}
		}
		cout << endl;
	}
	return 0;
}
