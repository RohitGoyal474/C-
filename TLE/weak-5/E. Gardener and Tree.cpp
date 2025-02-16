
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
#define rep(i, a, b) for (int i = a; i < b; ++i)

void solve(){
    int n,k;
    cin>>n>>k;
    vector<vector<int>>adj(n+1,vector<int>());
    vector<int>deg(n+1,0);
    

    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        deg[x]++;
        deg[y]++;
    }
    queue<int>q;
    // for(auto x:deg){
    //     if(x==1){
    //         q.push(x);
    //     }
    // }
    for(int i=1;i<=n;i++){
        if(deg[i]==1){
            q.push(i);
        }
    }
    int cnt=0;
    while(!q.empty() && k--){
        int s=q.size();
        for(int i=0;i<s;i++){
            int node=q.front();
            q.pop();
            cnt++;
            for(auto x:adj[node]){
                deg[x]--;
                if(deg[x]==1){
                    q.push(x);
                }
            }
        }
    }
    if(n==1 && k>0){
        cout<<0<<endl;
    }else{
        cout<<n-cnt<<endl;
    }
    

}


int main() {
    
    int noOfCases;
    cin>>noOfCases;
    while(noOfCases--){
        solve();
    }

    return 0;
}
