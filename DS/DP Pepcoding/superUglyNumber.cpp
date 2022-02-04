#include<bits/stdc++.h>
using namespace std;

int main()
{


	int n,k;
	cin>>n>>k;

	vector<int> primes(k),ind(k,0);

	for(int i=0;i<k;i++)
	{
		cin>>primes[i];
	}

	vector<int> a(n);

	a[0]=1;

	for(int i=1;i<n;i++)
	{

		int next=INT_MAX;

		for(int j=0;j<k;j++)
		{
			next=min(next,primes[j]*a[ind[j]]);
		}


		for(int j=0;j<k;j++)
		{
			if(next==(primes[j]*a[ind[j]]))
			{
				ind[j]++;
			}
		}

		a[i]=next;

	}

	cout<<a[n-1]<<endl;

	return 0;
}
