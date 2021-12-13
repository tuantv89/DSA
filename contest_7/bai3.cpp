#include <bits/stdc++.h>
using namespace std;
void reverse(string str)
{
	stack<char> st;
	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] != ' ')
			st.push(str[i]);
		else
		{
			while (st.empty() == false)
			{
				cout << st.top();
				st.pop();
			}
			cout << " ";
		}
	}
	while (st.empty() == false)
	{
		cout << st.top();
		st.pop();
	}
	cout << " ";
}
int main()
{
	int t;
	cin >> t;
	cin.ignore();
	while (t--)
	{
		string str;
		getline(cin, str);
		reverse(str);
		cout << endl;
	}
	return 0;
}
