#include <bits/stdc++.h>
using namespace std;
int main()
{
	string a;
	getline(cin, a, '\n');
	if ((a[0] - '0') + (a[4] - '0') == (a[8] - '0'))
		cout << "YES";
	else
		cout << "NO";
	return 0;
}
