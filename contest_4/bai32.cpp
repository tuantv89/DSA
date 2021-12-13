#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll merge(ll a[], int l, int mid, int r)
{
	ll cnt = 0;
	int size_l = mid - l + 1, size_r = r - mid;
	ll left[size_l], right[size_r];
	for (int i = 0; i < size_l; i++)
		left[i] = a[l + i];
	for (int i = 0; i < size_r; i++)
		right[i] = a[mid + i + 1];
	int i = 0, j = 0, k = l;
	while (i < size_l && j < size_r)
	{
		if (left[i] <= right[j])
		{
			a[k++] = left[i++];
		}
		else
		{
			a[k++] = right[j++];
			cnt += size_l - i;
		}
	}
	while (i < size_l)
	{
		a[k++] = left[i++];
	}
	while (j < size_r)
	{
		a[k++] = right[j++];
	}
	return cnt;
}

ll count_inversion(ll a[], int l, int r)
{
	ll ans = 0;
	int mid;
	if (r > l)
	{
		mid = (l + r) / 2;
		ans += count_inversion(a, l, mid);
		ans += count_inversion(a, mid + 1, r);
		ans += merge(a, l, mid, r);
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
		ll a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cout << count_inversion(a, 0, n - 1) << endl;
	}
	return 0;
}
