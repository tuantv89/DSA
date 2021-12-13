#include <bits/stdc++.h>
using namespace std;
int s[11];
int n;
void in()
{
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 0)
			cout << "A";
		else
			cout << "B";
	}
	cout << " ";
}
void Try(int i)
{
	for (int j = 0; j <= 1; j++)
	{
		s[i] = j;
		if (i == n - 1)
			in();
		else
			Try(i + 1);
	}
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		Try(0);
		cout << endl;
	}
	return 0;
}
