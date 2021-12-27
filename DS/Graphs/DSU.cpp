#include<bits/stdc++.h>
using namespace std;

// teo operations - find and union
// find gives the leader of the set, union is used to combine two sets
// optimizations - path compression (in find), union by rank (in union)


int dsu_find(int i,vector<int> &parent)
{

	if(parent[i]==i)
	{
		return i;
	}

	return parent[i]=dsu_find(parent[i],parent);
}


void dsu_union(int x,int y,vector<int> &parent,vector<int> &rank)
{

	int leader1 = dsu_find(x,parent);
	int leader2 = dsu_find(y,parent);

	if(leader1!=leader2)
	{

		if(rank[leader1]<rank[leader2])
		{
			parent[leader1]=leader2;
			rank[leader2]+=rank[leader1];
		}	
		else{
			parent[leader2]=leader1;
			rank[leader1]+=rank[leader2];
		}

	}

}


int main()
{

	int n;
	cin>>n;

	vector<int> parent(n);

	for(int i=0;i<n;i++)
	{
		parent[i]=i;
	}


	vector<int> rank(n,0);

	int op;

	int ctr;
	cin>>ctr;

	while(ctr--)
	{

		cin>>op;

		if(op==1)
		{
			// for find
			int x;
			cin>>x;

			cout<<dsu_find(x,parent)<<endl;

		}
		else if(op==2)
		{
			int x,y;
			cin>>x>>y;

			dsu_union(x,y,parent,rank);
		}
		else{
			break;
		}

	}

	return 0;
}
