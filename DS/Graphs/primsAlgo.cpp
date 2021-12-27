#include<bits/stdc++.h>
using namespace std;

class triplet{
	public:
		int curr,parent,edgeLength;

};

class compare{
	public:
		bool operator()(triplet &x,triplet &y)
		{
			return x.edgeLength>y.edgeLength;
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

	for(int i=0;i<noe;i++)
	{
		int x,y,len;
		cin>>x>>y>>len;

		m[x].push_back({y,len});
		m[y].push_back({x,len});
	}


	priority_queue<triplet,vector<triplet>,compare> q;

	q.push({0,-1,0});

	int ctr=0;
	int mst=0;

	while(!q.empty())
	{
		triplet temp=q.top();

		if(visited[temp.curr])
		{
			q.pop();
			continue;
		}

		cout<<temp.parent<<" --> "<<temp.curr<<endl;

		mst+=temp.edgeLength;
		q.pop();
		visited[temp.curr]=1;

		for(auto i:m[temp.curr])
		{
			q.push({i[0],temp.curr,i[1]});
		}

	}

	cout<<mst<<endl;

	return 0;
}
