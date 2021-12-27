#include<bits/stdc++.h>
using namespace std;

// Topological is the permutation of the nodes of the graph such that if we have the edge u->v,
// in topological sort, u appears before v

// Graph should be directed and acyclic
// Graph should have atleast one node with indegree = 0 (start point) and atleast one node with outdegree = 0 (destination point)


void ts(unordered_map<int,vector<int>> &m,int src,vector<int> &visited,vector<int> &a)
{

	visited[src]=1;

	for(auto i:m[src])
	{
		if(visited[i]==0)
		{
			ts(m,i,visited,a);
		}
	}

	a.push_back(src);

}


int main()
{

	int n;
	cin>>n;

	unordered_map<int,vector<int>> m;

	vector<int> visited(n,0);
	int noe;
	cin>>noe;

	for(int i=0;i<noe;i++)
	{
		int u,v;
		cin>>u>>v;

		m[u].push_back(v);
	}

	vector<int> topo;	


	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			ts(m,i,visited,topo);
		}
	}

	reverse(topo.begin(),topo.end());

	for(int i=0;i<topo.size();i++)
	{
		cout<<topo[i]<<" ";
	}
	cout<<endl;

	return 0;
}
