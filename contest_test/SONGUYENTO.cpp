#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	int dem = 1;
	while (t--)
	{

		int n;
		cin >> n;
		cout << "Test " << dem << ": ";
		for (int i = 2; i <= n; i++)
		{
			int dem = 0;
			while (n % i == 0)
			{
				dem++;
				n /= i;
			}
			if (dem)
				cout << i << "(" << dem << ")"
					 << " ";
			if (n > i)
				cout << " ";
		}
		dem++;
		cout << endl;
	}
	return 0;
}
