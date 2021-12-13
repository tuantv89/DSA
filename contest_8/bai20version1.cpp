#include <bits/stdc++.h>
using namespace std;
struct data
{
	int v[11];
	int d;
};
data x;
bool kt(int v[])
{
	return (v[0] == 1 && v[1] == 2 && v[2] == 3 && v[3] == 8 && v[4] == 0 &&
			v[5] == 0 && v[6] == 4 && v[7] == 7 && v[8] == 6 && v[9] == 5);
}
data Xoay(int lr, data a)
{
	if (lr == 1)
	{
		int t = a.v[0];
		a.v[0] = a.v[3];
		a.v[3] = a.v[7];
		a.v[7] = a.v[8];
		a.v[8] = a.v[5];
		a.v[5] = a.v[1];
		a.v[1] = t;
	}
	if (lr == 0)
	{
		int t = a.v[1];
		a.v[1] = a.v[4];
		a.v[4] = a.v[8];
		a.v[8] = a.v[9];
		a.v[9] = a.v[6];
		a.v[6] = a.v[2];
		a.v[2] = t;
	}
	return a;
}

void Try()
{
	if (kt(x.v))
	{
		cout << x.d;
		return;
	}
	data b;
	queue<data> q;
	q.push(x);
	while (!q.empty())
	{
		data c = q.front();
		q.pop();
		b = Xoay(0, c);
		b.d++;
		if (kt(b.v))
		{
			cout << b.d;
			return;
		}
		q.push(b);
		b = Xoay(1, c);
		b.d++;
		if (kt(b.v))
		{
			cout << b.d;
			return;
		}
		q.push(b);
	}
}
int main()
{
	x.d = 0;
	for (int i = 0; i < 10; i++)
	{
		cin >> x.v[i];
	}
	Try();
	return 0;
}
