#include<bits/stdc++.h>
using namespace std;

void buildSegmentTree(vector<int> &a,int s,int e,vector<int> &tree,int index)
{

    if(s==e)
    {
        tree[index]=a[s];
        return;
    }

    int mid=(s+e)/2;

    buildSegmentTree(a,s,mid,tree,2*index);
    buildSegmentTree(a,mid+1,e,tree,2*index+1);

    tree[index]=min(tree[2*index],tree[2*index+1]);

}

int rangeQuery(vector<int> tree,int s,int e,int l,int r,int index)
{

    // Base case -- complete overlap
    // node range completely inside query range
    if(s>=l && e<=r)
    {
        return tree[index]; 
    }

    // Base case -- no overlap

    if(l>e || s>r)
    {
        return INT_MAX;
    }

    // Otherwise partial overlap --call on both sides
    int mid=(s+e)/2;
    return min(rangeQuery(tree,s,mid,l,r,2*index),rangeQuery(tree,mid+1,e,l,r,2*index+1));
    
}

void updateIndex(vector<int> &tree,int s,int e,int ind,int value,int index)
{

    if(ind<s || ind>e)
    {
        return;
    }

    // if s==e, this means s==e==ind, so update the value

    if(s==e)
    {
        // update 
        tree[index]+=value;

        return;
    }

    // Recursive calls on left and right

    int mid=(s+e)/2;
    updateIndex(tree,s,mid,ind,value,2*index);
    updateIndex(tree,mid+1,e,ind,value,2*index+1);

    tree[index]=min(tree[2*index],tree[2*index+1]);

}


void updateRange(vector<int> &tree,int s,int e,int l, int r,int value,int index)
{

    // No Overlap
    if(s>r || e<l)
    {
        return;
    }

    // If leaf element, increment by value since this leaf lies within range

    if(s==e)
    {
        tree[index]+=value;
        return;
    }

    // Partial / Complete overlap -> call left and right
    int mid=(s+e)/2;
    
    updateRange(tree,s,mid,l,r,value,2*index);
    updateRange(tree,mid+1,e,l,r,value,2*index+1);

    tree[index]=min(tree[2*index],tree[2*index+1]);


}

int main() {

    vector<int> a={1,3,2,-5,6,4};
    int n=a.size();

    vector<int> tree(4*n+1,INT_MAX);
    buildSegmentTree(a,0,n-1,tree,1);

    for(int i=0;i<tree.size();i++)
    {
        cout<<tree[i]<<" ";
    } 

    cout<<endl;

    int q;

    // Finding minimum oin the given range
    cin>>q;

    while(q--)
    {
        int l,r;
        cin>>l>>r;

        cout<<rangeQuery(tree,0,n-1,l,r,1)<<endl;

    }

    // Updating elements and incrementing them with some value

    cin>>q;

    while(q--)
    {
        int ind,value;
        cin>>ind>>value;

        updateIndex(tree,0,n-1,ind,value,1);

    }

    for(int i=0;i<n;i++)
    {
        cout<<rangeQuery(tree,0,n-1,i,i,1)<<" ";
    } 

    cout<<endl;

    // Range Updation

    cin>>q;
    while(q--)
    {
        int l,r,value;
        cin>>l>>r>>value;

        updateRange(tree,0,n-1,l,r,value,1);
    }

    for(int i=0;i<n;i++)
    {
        cout<<rangeQuery(tree,0,n-1,i,i,1)<<" ";
    } 

    cout<<endl;

}
