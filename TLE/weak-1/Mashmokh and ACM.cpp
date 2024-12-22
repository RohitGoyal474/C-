
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
    int mod=1000000007;
    vector<vector<int>>dp(k+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++){
        dp[k][i]=1;
    }
    for(int i=k-1;i>=0;i--){
        for(int j=1;j<=n;j++){
            int sum=0;
            int last=j;
            for(int current=last; current<=n; current+=last ){
                sum=(sum+dp[i+1][current])%mod;
            }
            dp[i][j]=sum;
        }
    }
    cout<<dp[0][1]<<endl;

    return 0;
}
