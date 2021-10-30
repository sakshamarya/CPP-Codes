#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    long long int ans=1;
    int i=2;
    
    while(n>1)
    {
        
        int ctr=0;
        
        while(n%i==0)
        {
            ctr++;
            n/=i;
        }
        
        if(ctr)
        {
            ans=ans*(pow(i,ctr)-pow(i,ctr-1));
        }
        i++;
        
    }
    
    cout<<ans<<endl;
    
    return 0;
    
}