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

int solve1(unordered_map<int,vector<int>> &m,int src,int parent,vector<int> &preorder, vector<int> &lowestLink, vector<int> &visited, vector<int> &articulationPoints)
{

	visited[src]=1;
	preorder[src]=preorderNumber;
	preorderNumber++;

	int aageSeMinLowestLink=INT_MAX;
	int countUnvisited=0; // to check whether the src vertex has more than 1 connected component of the graph

	for(auto i:m[src])
	{
		if(!visited[i])
		{
			countUnvisited++;
			// finding aage se least lowest links in dfs
			aageSeMinLowestLink=min(aageSeMinLowestLink,solve1(m,i,src,preorder,lowestLink,visited,articulationPoints));
		}
		else{
			if(i!=parent)
			{
				// this is a back edge, update lowest links
				lowestLink[src]=min(lowestLink[src],preorder[i]);
			}
		}
	}

	if(countUnvisited>=2 || (aageSeMinLowestLink!=INT_MAX && aageSeMinLowestLink>preorder[src]))
	{
		articulationPoints.push_back(src);
	}

	// update lowestlinks since aage se chhota aa skta hai
	lowestLink[src]=min(lowestLink[src],aageSeMinLowestLink);
	
	return lowestLink[src];

}


// void findArticulationPoints(unordered_map<int,vector<int>> &m,int src,vector<int> &preorder,vector<int> &lowestLink,vector<int> &visited2,vector<int> &articulationPoints)
// {
// 	visited2[src]=1;

// 	int countUnvisited=0; // to check whether the src point is connected to multiple graph connected components or not

// 	int aageSeMinLowestLink=INT_MAX;

// 	int pushed=0; // to check whether I have pushed the src to articulationPoints array

// 	if(m[src].size() !=1 && lowestLink[src]>=preorder[src])
// 	{
// 		pushed=1;
// 		articulationPoints.push_back(src);
// 	}

// 	for(auto i:m[src])
// 	{
// 		if(!visited2[i])
// 		{
// 			countUnvisited++;
// 			findArticulationPoints(m,i,preorder,lowestLink,visited2,articulationPoints);
// 		}
// 	}

// 	if(countUnvisited>=2 && !pushed)
// 	{	
// 		articulationPoints.push_back(src);
// 	}

// }
	
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
	vector<int> articulationPoints;

	solve1(m,0,-1,preorder,lowestLink,visited,articulationPoints);
	

	// findArticulationPoints(m,0,preorder,lowestLink,visited2,articulationPoints);

	cout<<"articulationPoints are:"<<endl;

	for(auto i:articulationPoints)
	{
		cout<<i<<" ";
	}
	cout<<endl;

	return 0;
}
