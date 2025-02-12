
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




int main() {
    
    int n;
    int mod=1e9+7;
    cin>>n;
    vector<int>prev(4,0);
    vector<int>curr(4,0);
    // vector<vector<int>>dp(n+1,vector<int>(4,0));/
    // dp[n][3]=1;/
    prev[3]=1;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<4;j++){
            int val=0;
            for(int v=0;v<4;v++){
                if(v!=j){
                    // val=(dp[i+1][v]+val)%mod;
                    val=(prev[v]+val)%mod;
                }
            }
            // dp[i][j]=val;
            curr[j]=val;
        }
        prev=curr;
    }
    cout<<curr[3]<<endl;
    return 0;
}
