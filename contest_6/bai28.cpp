#include <bits/stdc++.h>
using namespace std;
void insert_sort(int a[], int n)
{
	cout << "Buoc " << 0 << ": " << a[0] << endl;
	int tmp;
	for (int i = 1; i < n; i++)
	{
		tmp = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > tmp)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = tmp;
		cout << "Buoc " << i << ": ";
		for (int k = 0; k <= i; k++)
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
	insert_sort(a, n);
	return 0;
}
