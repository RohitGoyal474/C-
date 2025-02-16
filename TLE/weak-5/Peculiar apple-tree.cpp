
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

void solve(int node,int parent,vector<vector<int>>& adj){
    int ans=0;
    queue<int>q;
    q.push(node);
    while(!q.empty()){
        int s=q.size();
        if(s%2!=0){
            ans++;
        }
        for(int i=0;i<s;i++){
            int node=q.front();
            q.pop();
            for(auto x:adj[node]){
                    q.push(x);
            }
        }
    }
    cout<<ans<<endl;
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
    // vector<int>res(n+1);
    solve(1,0,adj);
    // cout<<res[1]<<endl;

    return 0;
}
