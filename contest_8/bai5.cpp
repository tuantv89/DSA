#include <bits/stdc++.h>
using namespace std;
void binary(int n)
{
	queue<string> q;
	q.push("1");
	while (n--)
	{
		string s1 = q.front();
		q.pop();
		cout << s1 << " ";
		string s2 = s1;
		q.push(s1 + "0");
		q.push(s2 + "1");
	}
	cout << endl;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		binary(n);
	}
	return 0;
}
