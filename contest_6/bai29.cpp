#include <bits/stdc++.h>
using namespace std;
void bubble_sort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int ok = 0;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				ok = 1;
			}
		}
		if (ok == 0)
			break;
		cout << "Buoc " << i + 1 << ": ";
		for (int k = 0; k < n; k++)
			cout << a[k] << " ";
		cout << endl;
	}
}
int main()
{
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	bubble_sort(a, n);
	return 0;
}
