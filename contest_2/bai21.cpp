#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	cin.ignore();
	while (t--)
	{
		string s;
		cin >> s;
		cout << s << " ";
		while (next_permutation(s.begin(), s.end()))
		{
			cout << s << " ";
		}
		cout << endl;
	}
	return 0;
}
