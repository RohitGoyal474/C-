
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
    
    int n,m;
    cin>>n>>m;
    vector<int>arr(n);
    for(auto &x:arr)cin>>x;

    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=m;i++)dp[n][i]=1;

    for(int i=n-1;i>=0;i--){
        for(int j=1;j<=m;j++){
            if(arr[i]==0){
                for(int ii=-1;ii<2;ii++){
                    if(j+ii>0 && j+ii<=m){
                        dp[i][j]+=dp[i+1][j+ii];
                    }
                }
            }
            else{
                if(abs(arr[i]-j)<=1){
                    dp[i][j]=dp[i+1][arr[i]];
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        cout<< i << "   "<< dp[0][i]<<endl;
        ans += dp[0][i];  // Sum all valid ways
    }

    cout << ans << endl;


    return 0;
}
