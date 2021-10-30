#include<iostream>
using namespace std;

int gcd(int a,int b)
{
    if(b==0)
    {
        return a;
    }
    
    return gcd(b,a%b);
}

class dio{
    public:
    int x;
    int y;
};

dio solve(int a,int b,int g)
{
    dio temp;
    
    if(b==0)
    {
        temp.x=1;
        temp.y=0;
        
        return temp;
    }
    
    dio aage=solve(b,a%b,g);
    
    temp.x=aage.y;
    temp.y=aage.x-((a/b)*aage.y);
    
    return temp;
}

int main()
{
    int a,b;
    cin>>a>>b;
    
    dio ans=solve(a,b,gcd(a,b));
    
    cout<<ans.x<<" "<<ans.y<<endl;
    
}