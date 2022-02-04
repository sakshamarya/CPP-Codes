#include<bits/stdc++.h>
using namespace std;

#define ll long long int

long long int onesComplement(long long int n)
{

	long long int ans=0;
	int i=0;

	while(n)
	{
		if(n%2==0)
		{
			ans+=pow(2,i);
		}

		i++;
		n/=2;
	}

	return ans;

}

long long int power(int n)
{

	long long int ans=1;
	int curr=2;

	while(n)
	{
		if(n%2)
		{
			ans*=curr;
		}

		curr=curr*curr;
		n/=2;
	}

	return ans;

}

void solve()
{
	int l;
	cin>>l;

	

	long long int ans=0;

	while(l>1)
	{

		long long int n=log2(l);
		n++;

		long long int x=power(n)-2;
		long long int y=l;

		// cout<<x<<" "<<y<<endl;
		long long int temp1=min(x,y);
		long long int temp2=onesComplement(temp1);


		// cout<<"complement of "<<temp1<<" is "<<temp2<<" and "<<pow(2,n)-1<<endl;

		ans+=(temp1-temp2+1)*(power(n)-1);
		// cout<<ans<<endl;
		l=temp2-1;

	}

	cout<<ans<<endl;

}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        solve();
    }

}
