#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
/*void merge(int a[],int l,int m,int r)
{
	int n1=m-l+1,n2=r-m;
	int L[n1],R[n2];
	for(int i=0;i<n1;i++)
	L[i]=a[l+i];
	for(int i=0;i<n2;i++)
	R[i]=a[m+1+i];
	int i=0,j=0,k=l;
	while(i<n1 && j<n2)
	{
		if(L[i]<=R[j])
		{
			a[k++]=L[i++];
		}
		else a[k++]=R[j++];
	}
	while(i<n1) a[k++]=L[i++];
	while(j<n2) a[k++]=R[j++];
}
void mergesort(int a[],int l,int r)
{
	if(l<r)
	{
		int m=(r+l)/2;
		mergesort(a,l,m);
		mergesort(a,m+1,r);
		merge(a,l,m,r);
	}
}*/
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		int a[n]; //,b[n],t=0;
		// map<int,int> m;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			// if(m[a[i]]==0)
			// b[t++]=a[i];
			// m[a[i]]++;
		}
		sort(a, a + n);
		ll ans = 0;
		int i = 0;
		while (i < n)
		{
			int j = upper_bound(a + i + 1, a + n, a[i] + k - 1) - a - i - 1;
			ans += j;
			i++;
		}
		cout << ans << endl;
	}
	return 0;
}
