#include <bits/stdc++.h>
using namespace std;

int maxSum(int a[], int size)
{
	int ans = INT_MIN, max_here = 0;

	for (int i = 0; i < size; i++)
	{
		max_here = max_here + a[i];
		if (ans < max_here)
			ans = max_here;

		if (max_here < 0)
			max_here = 0;
	}
	return ans;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cout << maxSum(a, n) << endl;
	}
	return 0;
}
