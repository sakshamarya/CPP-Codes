#include<bits/stdc++.h>
using namespace std;

/*
	CONCEPT OF BRIDGES

	A cut edges / bridge is an edges removing which, a graph gets broken into 2 or more connected components
	-- done from algorithm live

	keep track of two things --
	i) forward edges
	ii) back edges

	maintain teo arrays
	i) preorder number : for number corresponding to forward edges
	ii) lowest link : to store the lowest level a back edge can take to from a node


	CONCEPT OF ARTICULATION POINTS
	While traversing in dfs, a point is considered as an articulation point if it satisfies one of the following two 
	conditions
	i) if the point is connected to two or more components. This can be handled by taking count of the non visited points from a 
	particular point
	ii) if there exist no point in its subtree with lowestLink value less than the parent point's preorderNumber


*/
int preorderNumber;

int solve1(unordered_map<int,vector<int>> &m,int src,int parent,vector<int> &preorder, vector<int> &lowestLink, vector<int> &visited, vector<vector<int>> &bridges)
{

	visited[src]=1;
	preorder[src]=preorderNumber;
	preorderNumber++;

	int aageSeMinLowestLink=INT_MAX;

	for(auto i:m[src])
	{
		if(!visited[i])
		{
			// finding aage se least lowest links in dfs
			aageSeMinLowestLink=min(aageSeMinLowestLink,solve1(m,i,src,preorder,lowestLink,visited,bridges));

			if(lowestLink[i]>preorder[src])
			{
				bridges.push_back({i,src});
			}
		}
		else{
			if(i!=parent)
			{
				// this is a back edge, update lowest links
				lowestLink[src]=min(lowestLink[src],preorder[i]);
			}
		}
	}

	// update lowestlinks since aage se chhota aa skta hai
	lowestLink[src]=min(lowestLink[src],aageSeMinLowestLink);
	
	return lowestLink[src];

}

	
int main()
{

	int v,e;
	cin>>v>>e;

	unordered_map<int,vector<int>> m;
	vector<vector<int>> edges;

	for(int i=0;i<e;i++)
	{
		int x,y;
		cin>>x>>y;
		edges.push_back({x,y});

		m[x].push_back(y);
		m[y].push_back(x);
	}


	vector<int> preorder(v),lowestLink(v,INT_MAX);

	vector<int> visited(v,0);

	preorderNumber=0;
	vector<vector<int>> bridges;

	solve1(m,0,-1,preorder,lowestLink,visited,bridges);
	
	cout<<"bridges are: "<<endl;

	for(auto i:bridges)
	{
		cout<<i[0]<<" "<<i[1]<<endl;
	}

	return 0;
}
