#include<bits/stdc++.h>
using namespace std;


/*

	uses a bit array to store ranges

	some bitmasking concepts -- 
	for a number x, x&(-x) removes the last set bit from the number x

	bit[i] stores the answer of the range [(i&(-i))+1, i]


	example, 15th index stores answer for the range [15&(-15) + 1, 15] => [15,15]
	14th index stores for the range [14&(-14)+1,14] => [13, 14]
	
	range sum and range update functions written in the notes
*/


void update(vector<int> &bit,int ind,int x){

	// we have to take all the ranges which contains the number i
	for(int i=ind;i<bit.size();i=(i+(i&(-i)))){
		bit[i]+=x;
	}

}

int sum(vector<int> &bit, int r){

	int ans=0;

	for(int i=r;i>0;i=(i-(i&(-i)))){
		ans+=bit[i];
	}

	return ans;
}

int main()
{

	int n;
	cin>>n;

	vector<int> a(n);

	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}

	vector<int> bit(n+1,0); // 1 based indexing

	for(int i=0;i<n;i++){
		update(bit,i+1,a[i]);
	}

	int q;
	cin>>q;

	while(q--){

		int t;
		cin>>t;

		//query type 1: ind, x -- enter index ind '1' based
		// query type 2: range sum from l to r -- enter l,r '1' based

		if(t==1){
			int ind,x;
			cin>>ind>>x;

			update(bit,ind,x);
		}
		else{
			int l,r;
			cin>>l>>r;
			cout<<sum(bit,r)-sum(bit,l-1)<<endl;
		}

	}


	return 0;
}
