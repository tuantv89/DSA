#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define Max 10
ll p[90];
void init()
{
	p[0] = 1;
	p[1] = 1;
	for (int i = 2; i < 81; i++)
	{
		p[i] = p[i - 1] + p[i - 2];
	}
}

void matranoc(int x, ll a[][Max])
{
	int gt = 0;
	int i;
	int d = x, t = 1;
	while (d)
	{
		for (i = t; i <= d; i++) // gan gia tri tu trai sang phai
		{
			a[t][i] = p[gt++];
		}
		for (i = t + 1; i <= d; i++) // tu tren xuong
		{
			a[i][d] = p[gt++];
		}
		for (i = d - 1; i >= t; i--) // tu phai qua trai
		{
			a[d][i] = p[gt++];
		}
		for (i = d - 1; i >= t + 1; i--) // tu duoi len tren
		{
			a[i][t] = p[gt++];
		}
		t++; //
		d--; // dieu kien thu nho xoan oc
	}
	for (i = 1; i <= x; i++)
	{
		for (int j = 1; j <= x; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}
int main()
{
	int t;
	cin >> t;
	int dem = 1;
	init();
	while (t--)
	{
		int n;
		cin >> n;
		ll a[Max][Max];
		cout << "Test"
			 << " " << dem << ":" << endl;
		matranoc(n, a);
		dem++;
	}
	return 0;
}
