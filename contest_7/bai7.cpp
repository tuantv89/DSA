#include <iostream>
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
		int l = s.size();
		int cnt = 0, ans = 0;
		for (int i = 0; i < l; i++)
		{
			if (s[i] == '(')
				cnt++;

			if (s[i] == ')')
				cnt--;

			if (cnt < 0)
			{
				cnt = 1;
				ans++;
			}
		}
		ans = ans + cnt / 2;
		cout << ans << endl;
	}
	return 0;
}
