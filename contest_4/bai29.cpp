#include <bits/stdc++.h>
using namespace std;

typedef pair<double, double> point;
vector<point> p;

int compare_Y(point a, point b)
{
	return a.second > b.second;
}

double distance(point a, point b)
{
	return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

double vet_can(int l, int r)
{
	double min_dis = DBL_MAX;
	for (int i = l; i <= r - 1; i++)
	{
		for (int j = i + 1; j <= r; j++)
		{
			if (distance(p[i], p[j]) < min_dis)
				min_dis = distance(p[i], p[j]);
		}
	}
	return min_dis;
}

double min(double x, double y)
{
	return (x < y) ? x : y;
}

double min_strip(vector<point> strip, double d)
{
	double Min = d;
	sort(strip.begin(), strip.end(), compare_Y);
	for (int i = 0; i < strip.size() - 1; i++)
	{
		for (int j = i + 1; j < strip.size() && (strip[j].second - strip[i].second) < Min; j++)
		{
			if (distance(strip[i], strip[j]) < Min)
				Min = distance(strip[i], strip[j]);
		}
	}
	return Min;
}

double closet(int l, int r)
{
	if (r - l <= 3)
		return vet_can(l, r);
	int mid = (l + r) / 2;
	point midp = p[mid];
	double dl = closet(l, mid);
	double dr = closet(mid + 1, r);
	double d = min(dl, dr);
	vector<point> strip;
	for (int i = l; i <= r; i++)
	{
		if (abs(p[i].first - midp.first) < d)
		{
			strip.push_back(p[i]);
		}
	}
	return min(d, min_strip(strip, d));
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		p.resize(n);
		for (int i = 0; i < n; i++)
		{
			cin >> p[i].first >> p[i].second;
		}
		sort(p.begin(), p.end());
		cout << setprecision(6) << fixed << closet(0, n - 1) << endl;
	}
	return 0;
}
