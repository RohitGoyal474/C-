
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
    
        int n,k;
        cin>>n>>k;
        vector<int>candy(n+1);
         candy[0]=0;
        for(int i=1;i<=n;i++){
            cin>>candy[i];
        }
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));
        dp[n][0]=1;
        vector<int>presum(n+1,0);
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=k;j++){

                // for(int c=0;c<=candy[i+1];c++){
                //     // int take_candy=0,not_take_candy=0;
                //     // int val=candy[c];
                //     if(c<=j){
                //         dp[i][j]+=dp[i+1][j-c];
                //     }
                // }
            }
        }
        cout<<dp[0][k]<<endl;
    return 0;
}
