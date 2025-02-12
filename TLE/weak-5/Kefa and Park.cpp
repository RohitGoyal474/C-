
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <bitset>
#include <numeric>
#include <limits>
#include <iomanip>
using namespace std;
int solve(int node,int parent,vector<vector<int>>&adj,vector<int>cat,int k,int cat_count){
    if(cat[node]==1)cat_count++;
    else cat_count=0;
    if(cat_count>k)return 0;
    
    if(adj[node].size()==1 && node!=0)return 1;
    int ans=0;
    for(auto x:adj[node]){
        if(x!=parent){
            ans+=solve(x,node,adj,cat,k,cat_count);
        }
    }
    return ans;
}



int main() {
    int n,k;
    cin>>n>>k;
    vector<vector<int>>adj(n+1,vector<int>());
    vector<int>cat(n+1);
    for(int i=1;i<=n;i++){
        cin>>cat[i];
    }
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int ans= solve(1,0,adj,cat,k,0);    
    cout<<ans<<endl;
    // return 0;
}
