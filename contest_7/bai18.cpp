#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int prec(char c)
{
	if (c == '+' || c == '-')
		return 1;
	if (c == '*' || c == '/')
		return 2;
	return 0;
}
ll tinh(ll x, ll y, char c)
{
	if (c == '+')
		return x + y;
	if (c == '-')
		return x - y;
	if (c == '*')
		return x * y;
	if (c == '/')
		return x / y;
}
ll caculate(string s)
{
	int n = s.length();
	stack<char> op;
	stack<ll> val;
	for (int i = 0; i < n; i++)
	{
		// if(s[i]==' ')
		// continue;
		// else
		if (s[i] == '(')
			op.push(s[i]);
		else if (isdigit(s[i]))
		{
			ll tmp = 0;
			while (i < n && isdigit(s[i]))
			{
				tmp = (tmp * 10) + (s[i] - '0');
				i++;
			}
			i--;
			val.push(tmp);
		}
		else if (s[i] == ')')
		{
			while (!op.empty() && op.top() != '(')
			{
				ll val2 = val.top();
				val.pop();
				ll val1 = val.top();
				val.pop();
				char c = op.top();
				op.pop();
				val.push(tinh(val1, val2, c));
			}
			if (!op.empty() && op.top() == '(')
				op.pop();
		}
		else
		{
			while (!op.empty() && prec(op.top()) >= prec(s[i]))
			{
				ll val2 = val.top();
				val.pop();
				ll val1 = val.top();
				val.pop();
				char c = op.top();
				op.pop();
				val.push(tinh(val1, val2, c));
			}
			op.push(s[i]);
		}
	}
	while (!op.empty())
	{
		ll val2 = val.top();
		val.pop();
		ll val1 = val.top();
		val.pop();
		char c = op.top();
		op.pop();
		val.push(tinh(val1, val2, c));
	}
	return val.top();
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		cout << caculate(s) << endl;
	}
	return 0;
}
