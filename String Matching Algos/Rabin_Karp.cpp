#include<bits/stdc++.h>
using namespace std;

int main()
{


	string text;
	cin>>text;

	string pattern;
	cin>>pattern;

	int n=text.size();
	int m=pattern.size();

	// building longest prefix sum for the pattern string
	vector<int> lps(m);

	lps[0]=0;

	int i=1,j=0;

	while(i<m)
	{

		if(pattern[i]==pattern[j])
		{
			lps[i]=1+j;
			j++;
			i++;
		}
		else{

			while(j>0 && pattern[j]!=pattern[i])
			{
				j=lps[j-1];
			}

			if(pattern[j]==pattern[i])
			{
				lps[i]=1+j;
				i++;
				j++;
			}
			else{
				lps[i]=0;
				i++;
			}
		}
	}


	// applying the algorithm

	i=0,j=0;



	while(i<text.size() && j<pattern.size())
	{
		if(text[i]==pattern[j])
		{
			i++;
			j++;
		}
		else{

			if(j-1>=0)
			{
				j=lps[j-1];
			}
			else{
				i++;
			}
		}
	}

	if(j==pattern.size())
	{
		cout<<"pattern exists"<<endl;
	}
	else{
		cout<<"pattern does not exists"<<endl;
	}

	return 0;
}
