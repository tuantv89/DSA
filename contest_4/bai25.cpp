#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull F[100];
void init()
{
	F[1] = 1;
	F[2] = 1;
	for (int i = 3; i < 93; i++)
		F[i] = F[i - 1] + F[i - 2];
}
char find(int n, ull i)
{
	if (n == 1)
		return 'A';
	if (n == 2)
		return 'B';
	if (i <= F[n - 2])
		return find(n - 2, i);
	return find(n - 1, i - F[n - 2]);
}

int main()
{
	int t;
	cin >> t;
	init();
	cout << F[92] << endl;
	while (t--)
	{
		int n;
		ull i;
		cin >> n >> i;
		cout << find(n, i) << endl;
	}
	return 0;
}
