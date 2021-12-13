#include <bits/stdc++.h>
using namespace std;
#define M 1000000
int p[M + 5];
void sang()
{
	for (int i = 0; i <= M; i++)
		p[i] = 1;
	p[0] = 0;
	p[1] = 0;
	for (int i = 2; i <= M; i++)
	{
		if (p[i])
		{
			for (int j = 2 * i; j <= M; j += i)
				p[j] = 0;
		}
	}
}
int main()
{
	int t;
	cin >> t;
	sang();
	while (t--)
	{
		int n;
		cin >> n;
		int flag = 0;
		for (int i = 2; i <= n; i++)
		{
			if (p[i] && p[n - i])
			{
				flag = 1;
				cout << i << " " << n - i << endl;
				break;
			}
		}
		if (flag == 0)
			cout << -1 << endl;
	}
	return 0;
}
