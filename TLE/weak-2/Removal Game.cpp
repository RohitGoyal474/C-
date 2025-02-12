
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
    cin>>n;
    vector<int>arr(n);

    for( auto &x:arr) cin>>x;
    vector<vector<long long>>dp(n+1,vector<long long>(n+1,0));
    // base case
    // if i==j dp[i][j]=arr[i]

    for(int i=0;i<n;i++){
        dp[i][i]=arr[i];
    }
    for(int i=n-2;i>=0;i--){
        for(int j=i+1;j<n;j++){
            long long left_take=arr[i]+min(dp[i+2][j],dp[i+1][j-1]);
            long long right_take=arr[j]+min(dp[i+1][j-1],dp[i][j-2]);
            dp[i][j]=max(left_take,right_take);
        }
    }
    cout<<dp[0][n-1]<<endl;
    return 0;
}
