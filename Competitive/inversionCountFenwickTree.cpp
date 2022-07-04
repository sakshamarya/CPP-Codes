
#include<bits/stdc++.h>
using namespace std;

#define ll long long int

void update(vector<ll> &bit,int ind){

	for(int i=ind;i<bit.size();i=(i+(i&(-i)))){
		bit[i]++;
	}
}

ll sum(vector<ll> &bit,int ind){

	ll ans=0;

	for(int i=ind;i>0;i=i-(i&(-i))){
		ans+=bit[i];
	}

	return ans;

}

void solve()
{

	string str;
	getline(cin,str);

	int n;
	cin>>n;

	vector<ll> a(n);

	set<ll> s;

	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		s.insert(a[i]);
	}

	unordered_map<int,ll> m;
	int ctr=1;


	while(!s.empty()){
		m[*s.begin()]=ctr;
		ctr++;
		s.erase(s.begin());
	}

	ll maxi=m[a[0]];

	for(int i=0;i<n;i++)
	{
		a[i]=m[a[i]];
		maxi=max(maxi,a[i]);
	}


	vector<ll> bit(maxi+1,0);

	ll ans=0;

	for(int i=0;i<n;i++)
	{
		ans+=sum(bit,maxi)-sum(bit,a[i]); // count of element > a[i] to the left of ith index which is same as the question description
		update(bit,a[i]);
	}
	cout<<endl;


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
