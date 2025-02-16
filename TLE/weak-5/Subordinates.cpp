
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

void solve(int node,int parent,vector<vector<int>>& adj,vector<int>& sub_ordinate){
    
   for(auto x:adj[node]){
        solve(x,node,adj,sub_ordinate);
   }
   for(auto x:adj[node]){
       sub_ordinate[node]+=sub_ordinate[x]+1;
   }
}


int main() {
    
    int n;
    cin>>n;
    vector<vector<int>>adj(n+1,vector<int>());
    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        adj[x].push_back(i);
    }
    vector<int>sub_ordinate(n+1,0);
    solve(1,0,adj,sub_ordinate);
    for(int i=1;i<=n;i++){
        cout<<sub_ordinate[i]<<" ";
    }
    return 0;
}
