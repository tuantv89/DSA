#include <bits/stdc++.h>
using namespace std;
int a[1005][1005];
int main()
{
	int n;
	cin >> n;
	memset(a, 0, sizeof(a));
	cin.ignore();
	for (int i = 1; i <= n; i++)
	{
		string s;
		getline(cin, s);
		for (int j = 0; j < s.length(); j++)
		{
			if (s[j] >= '1' && s[j] <= '9')
			{
				string tmp = "";
				while (isdigit(s[j]) && j < s.length())
				{
					tmp = tmp + string(1, s[j]);
					j++;
				}
				a[i][stoi(tmp)] = 1;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	return 0;
}
