
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

/// in this, just finding the min no.
void solve(){
    string s;
    cin>>s;
    int n=s.size();
    int no;
    cin>>no;
    vector<string>v(no);
    for(int i=0;i<no;i++)cin>>v[i];
    vector<vector<int>>dp(n+1,vector<int>(n+1,1e9));
    for(int i=n-1;i>=0;i--){
        for(int k=0;k<=n;k++){
            
            int pick=1e9;
            int non_pick=1e9;
            
            if(k>n-i){
                dp[i][k]=1e9;
                continue;
            }
            if(k==n-i){
                dp[i][k]=0;
                continue;
            }

            for(auto m:v){
                if(m.size()<=n-i && s.substr(i,m.size())==m){
                    int val=m.size();
                    pick=min(pick,1+dp[i+1][max(k-1,val-1)]);
                }
            }

            if(k>0){
                non_pick=dp[i+1][k-1];
            }
            dp[i][k]=min(pick,non_pick);
        }
    }
    cout<<dp[0][0]<<endl;
}


int main() {
    
    int noOfCases;
    cin>>noOfCases;
    while(noOfCases--){
        solve();
    }

    return 0;
}
