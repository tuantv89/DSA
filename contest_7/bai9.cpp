#include <bits/stdc++.h>
using namespace std;
string str;
vector<pair<int, int>> tmp;
int x[15], cnt = 0, n;
set<string> ans;
void update()
{
	string temp = "";
	for (int i = 0; i < str.length(); i++)
	{
		int ok = 1;
		for (int j = n - 1; j >= 0; j--)
		{
			if (x[j] == 1 && (tmp[j].first == i || tmp[j].second == i))
				ok = 0;
		}
		if (ok)
			temp = temp + string(1, str[i]);
	}
	ans.insert(temp);
}

void Try(int i)
{
	for (int j = 0; j <= 1; j++)
	{
		x[i] = j;
		cnt += j;
		if (i == 0)
		{
			if (cnt > 0)
				update();
		}
		else
			Try(i - 1);
		cnt -= j;
	}
}
int main()
{
	cnt = 0;
	cin >> str;
	stack<int> st;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(')
			st.push(i);
		else if (str[i] == ')')
		{
			if (!st.empty())
			{
				tmp.push_back(make_pair(st.top(), i));
				st.pop();
			}
		}
	}
	n = tmp.size();
	Try(n - 1);
	for (set<string>::iterator it = ans.begin(); it != ans.end(); it++)
		cout << *it << endl;
	return 0;
}
