#include<bits/stdc++.h>
using namespace std;


// Without DP, time complexity will be (n-1)! since we are check all the possible paths
//  After Dp, time complexity will be O(2^n * n * n)

int all_visited;

int tsp(vector<vector<int>> &a,int curr,int visited,vector<vector<int>> &dp)
{

	if(visited == all_visited)
	{
		// cout<<"reached"<<endl;
		return dp[visited][curr] = a[0][curr];
	}

	if(dp[visited][curr]!=-1)
	{
		return dp[visited][curr];
	}

	int ans=INT_MAX;

	for(int i=0;i<a.size();i++)
	{
		if((visited&(1<<i))==0)
		{
			ans=min(ans,a[curr][i]+tsp(a,i,visited|(1<<curr),dp));
		}
	}


	return dp[visited][curr]=ans;

}


int main()
{

	int n;
	cin>>n;

	vector<vector<int>> a(n,vector<int>(n));

	// adjacency matrix
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}

	// TSP - minimum cost hamiltonian tour - each node has to be visited only once, total cost should be minimum

	int visited=0;
	all_visited=pow(2,n)-1;

	vector<vector<int>> dp(pow(2,n),vector<int>(n,-1));

	cout<<tsp(a,0,visited,dp)<<endl; 

	return 0;
}
