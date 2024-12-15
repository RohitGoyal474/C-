
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
    int mod=1e9+7;
    int n,x;
    cin>>n>>x;
    vector<int>coin(n);
    for(int i=0;i<n;i++)cin>>coin[i];
    vector<vector<int>>dp(x+1,vector<int>(n+1,0));
    
    for(int i=1;i<=x;i++){
        for(int k=0;k<n;k++){
            if(i>=coin[k]){
                dp[i][k]=(dp[i-coin[k]][k]+ dp[i][k+1])%(mod);
            }
        }
    }
    cout<<dp[1][n-1];
    return 0;
}

// d[i][k] = d[i-coin[k]][k]+dp[i][k+1];
