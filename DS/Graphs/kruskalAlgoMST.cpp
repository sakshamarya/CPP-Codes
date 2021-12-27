#include<bits/stdc++.h>
using namespace std;

// select smallest length edge, take edge only if it does not leads to a cycle
// Use dsu


int dsu_find(int i,vector<int> &parent)
{

	if(i==parent[i])
	{
		return i;
	}

	return parent[i]=dsu_find(parent[i],parent);

}


void dsu_union(int x,int y,vector<int> &parent,vector<int> &rank)
{

	int s1=dsu_find(x,parent);
	int s2=dsu_find(y,parent);

	if(s1!=s2)
	{
		if(rank[s1]<rank[s2])
		{
			rank[s2]+=rank[s1];
			parent[s1]=s2;
		}
		else{
			rank[s1]+=rank[s2];
			parent[s2]=s1;
		}	
	}

}


class compare{
public:
	bool operator()(vector<int> const& a,vector<int> const& b)
	{
		return a[2]>b[2];

	}

};


int main()
{

	int n;
	cin>>n;

	int noe;
	cin>>noe;

	unordered_map<int,vector<vector<int>>> m;

	vector<int> visited(n,0);

	priority_queue<vector<int>,vector<vector<int>>, compare> q;

	for(int i=0;i<noe;i++)
	{
		int x,y,len;
		cin>>x>>y>>len;

		m[x].push_back({y,len});
		m[y].push_back({x,len});

		q.push({x,y,len});
	}

	vector<int> rank(n,1),parent(n);

	for(int i=0;i<n;i++)
	{
		parent[i]=i;
	}
	

	int ctr=0,mst=0;
	
	while(!q.empty())
	{
		vector<int> temp=q.top();
		int u=temp[0];
		int v=temp[1];
		int len=temp[2];

		q.pop();

		if(dsu_find(u,parent)!=dsu_find(v,parent))
		{

			cout<<u<<" --> "<<v<<endl;
			ctr++;
			mst+=len;
			dsu_union(u,v,parent,rank);
		}

		if(ctr==n-1)
		{
			break;
		}

	}


	cout<<mst<<endl;

	return 0;
}
