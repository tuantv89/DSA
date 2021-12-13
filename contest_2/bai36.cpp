#include <bits/stdc++.h>
using namespace std;
int b[10], check[10];
int a[10], tmp[10];
int operat[10], ok = 0;
void init()
{
	for (int i = 1; i <= 5; i++)
		check[i] = 1;
}
void swap()
{
	for (int i = 1; i <= 5; i++)
	{
		a[i] = tmp[b[i]];
	}
}
void back_track(int i)
{
	for (int j = 1; j <= 3; j++)
	{
		operat[i] = j;
		if (i == 4)
		{
			int s;
			if (operat[1] == 1)
				s = a[1] + a[2];
			else if (operat[1] == 2)
				s = a[1] - a[2];
			else
				s = a[1] * a[2];
			if (operat[2] == 1)
				s = s + a[3];
			else if (operat[2] == 2)
				s = s - a[3];
			else
				s = s * a[3];
			if (operat[3] == 1)
				s = s + a[4];
			else if (operat[3] == 2)
				s = s - a[4];
			else
				s = s * a[4];
			if (operat[4] == 1)
				s = s + a[5];
			else if (operat[4] == 2)
				s = s - a[5];
			else
				s = s * a[5];
			if (s == 23)
				ok = 1;
		}
		else
			back_track(i + 1);
	}
}

void Try(int i)
{
	for (int j = 1; j <= 5; j++)
	{
		if (check[j])
		{
			b[i] = j;
			check[j] = 0;
			if (i == 5)
			{
				swap();
				back_track(1);
			}
			else
				Try(i + 1);
			check[j] = 1;
		}
	}
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		ok = 0;
		init();
		for (int i = 1; i <= 5; i++)
		{
			cin >> a[i];
			tmp[i] = a[i];
		}
		Try(1);
		if (ok == 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
