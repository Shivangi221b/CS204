#include <bits/stdc++.h>

using namespace std; 

long long int median(long long int d[], long long int k)
{
	//Insertion sort
	long long int s, key;
	for (long long int r=1; r<k; r++)
	{
		s=r-1;
		key=d[r];
		while(s>=0 && d[s]>key)
		{
			d[s+1]=d[s];
			s--;
		}
		d[s+1]=key;
	}

	return d[k/2];
}

void swap(long long int *x, long long int *y)
{
	long long int t= *x;
	*x=*y;
	*y=t;
}

long long int part(long long int d[], long long int l, long long int r, long long int x)
{
	long long int  i;
	for(i=l; i<r; i++)
		if(d[i]==x)
			break;
	swap(&d[i], &d[r]);

	i=l;
	for(long long int  j=l; j<r; j++)
	{
		if (d[j]<=x)
		{
			swap(&d[i], &d[j]);
			i++;
		}
	} 
	swap(&d[i], &d[r]);
	return i;
}


long long int kSmallest(long long int d[], long long int l, long long int r, long long int k)
{
	if(k>0 && k<=r-l+1)
	{
	
		long long int n=r-l+1;
		long long int meds[(n+4)/5];
		long long int y;
		for(y=0; y<n/5; y++)
			meds[y]=median(d+l+y*5, 5);

		if(y*5<n)
		{
			meds[y]=median(d+l+y*5, n%5);
			y++;
		}

		long long int mom = (y==1)?meds[y-1]:kSmallest(meds, 0, y-1, y/2);

		long long int pos = part(d,l,r, mom);

		if(pos-l==k-1)
			return d[pos];
		if(pos-l>k-1)
			return kSmallest(d,l,pos-1,k);

		return kSmallest(d,pos+1,r,k-pos+l-1);
	}

 	return INT_MAX;
}

int main()
{
	long long int t, k, x, y;

	cin>>t;
	for (long long int i=0; i<t; i++)
	{
		cin>>k;
		long long int d[k];
		for(long long int j=0; j<k; j++)
		{
			cin>>x>>y;
			d[j]=(x*x)+(y*y);
		}	

		(k%2==0)?cout<<sqrt(kSmallest(d, 0, k-1, (k/2)))<<endl:cout<<sqrt(kSmallest(d, 0, k-1, (k/2)+1))<<endl;
	}	

	return 0;
}