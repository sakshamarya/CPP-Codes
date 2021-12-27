#include<bits/stdc++.h>
using namespace std;

// Topological is the permutation of the nodes of the graph such that if we have the edge u->v,
// in topological sort, u appears before v

// Graph should be directed and acyclic
// Graph should have atleast one node with indegree = 0 (start point) and atleast one node with outdegree = 0 (destination point)


int main()
{

	int n;
	cin>>n;

	unordered_map<int,vector<int>> m;

	vector<int> visited(n,0);
	int noe;
	cin>>noe;

	vector<int> ind(n,0); //indegree array

	for(int i=0;i<noe;i++)
	{
		int u,v;
		cin>>u>>v;

		m[u].push_back(v);
		ind[v]++;
	}

	vector<int> topo;

	queue<int> q;
	
	for(int i=0;i<ind.size();i++)
	{
		if(ind[i]==0)
		{
			q.push(i);
		}
	}

	while(!q.empty())
	{
		int temp=q.front();
		q.pop();
		topo.push_back(temp);


		for(auto i:m[temp])
		{
			ind[i]--;
			if(ind[i]==0)
			{
				q.push(i);
			}
		}

	}

	for(int i=0;i<topo.size();i++)
	{
		cout<<topo[i]<<" ";
	}
	cout<<endl;

	return 0;
}
