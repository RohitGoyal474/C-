
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

void solve(int root,int node,int parent,vector<vector<int>>& adj,vector<int>& good_child,vector<int>& ans){
   bool flag;
   if(node!=root && good_child[node]==1){
        flag=false;
    }
    else{
        flag=true;
    }
    
    for(auto x:adj[node]){
        // if(node=root)continue;
        if(node==root || good_child[x]==0 || good_child[node]==0){
            flag=true;
        }
        solve(root,x,node,adj,good_child,ans);
    }
    if(!flag){
        ans.push_back(node);
    }
}


int main() {
     int n;
    cin>>n;
    vector<vector<int>>adj(n+1,vector<int>());
    vector<int>good_child(n+1,0);
    int root;
    for(int i=1;i<=n;i++){
        int p,c;
        cin>>p>>c;
        if(p!=-1){good_child[i]=c;
        adj[p].push_back(i);
        }else{
            root=i;
        }
        
    }
    vector<int>ans;
    solve(root,root,0,adj,good_child,ans);
    sort(ans.begin(),ans.end());
    if(ans.size()==0){
        cout<<-1;
    }else{
        for(auto x:ans){
            cout<<x<<" ";
        }
    }

    return 0;
}
