#include <iostream>
using namespace std;
#include<bits/stdc++.h>

class compare{

    public:

    // adding const& saves time

    bool operator()(pair<int,string> const& a,pair<int,string> const& b)
    {
        if(a.first==b.first)
        {
            return a.second<b.second;
        }

        return a.first>b.first;
    }
};

int main() {

    // For Set data structure
    // set<pair<int,string>,compare> q;


    // For priority queue ->> the element that the comparator returns will be pushed first
    priority_queue<pair<int,string>,vector<pair<int,string>>,compare> q;
    

}
