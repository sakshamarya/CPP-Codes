#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// declaring a typedef
// --> replace less by greater to make pbds of descending order, or add a custom comparator
// --> replacing less with less_equal<int> will make it a multiset
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main() {

    // declaring pbds

    pbds s;

    // Insertion in pbds

    s.insert(1);
    s.insert(7);
    s.insert(9);
    s.insert(2);
    s.insert(3);
    s.insert(5);
    s.insert(1); //adding duplicate value

    for(auto i:s)
    {
        cout<<i<<endl;
    }

    // finding xth element

    int x=0;
    cout<<x<<"th element in set is "<<*s.find_by_order(x)<<endl;
    x=4;
    cout<<x<<"th element in set is "<<*s.find_by_order(x)<<endl;
    x=6; // 6>s.size()
    cout<<x<<"th element in set is "<<*s.find_by_order(x)<<endl; // giving output 0 for x>s.size()


    // no of elements less than x

    x=3;
    cout<<"no of elements strictly less than "<<x<<" are "<<s.order_of_key(x)<<endl;

    // deleting elements
    s.erase(2);
    s.erase(17); //not there in the set

    for(auto i:s)
    {
        cout<<i<<endl;
    }

}
