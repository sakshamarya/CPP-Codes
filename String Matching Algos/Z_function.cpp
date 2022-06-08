#include<bits/stdc++.h>
using namespace std;

vector<int> z_function(string s) {

    int n = s.size();

    vector<int> z(n);


    int l=0,r=0;

    for(int i=0;i<n;i++)
    {

    	if(i<=r)
    	{
    		z[i]=min(r-i+1,z[i-l]);
    	}

    	while(i+z[i]<n && s[z[i]]==s[i+z[i]])
    	{
    		z[i]++;
    	}

    	if((i+z[i]-1)>r)
    	{
    		l=i;
    		r=i+z[i]-1;
    	}

    }


    return z;
}


int main()
{

	string text,pattern;
	cin>>text;
	cin>>pattern;

	string combined;

	for(int i=0;i<pattern.size();i++)
	{
		combined.push_back(pattern[i]);
	}

	combined.push_back('#');

	for(int i=0;i<text.size();i++)
	{
		combined.push_back(text[i]);
	}

	vector<int> z = z_function(combined);

	int count=0;

	for(int i=pattern.size()+2;i<combined.size();i++)
	{
		if(z[i]==pattern.size())
		{
			count++;
		}
	}

	cout<<count<<endl;

	return 0;
}
