
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
    int mod=1e9+7;
    vector<vector<char>>arr(n,vector<char>(n));
    vector<vector<int>>dp(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<n;i++){
        if(arr[i][0]=='.'){
            dp[i][0]=1;
        }
        
        else{
            break;
        }
    }
    for(int i=0;i<n;i++){
        if(arr[0][i]=='.'){
            dp[0][i]=1;
        }
        
        else{
            break;
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(arr[i][j]=='.'){
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
            }
        }
    }
    cout<<dp[n-1][n-1]<<endl;

    

    return 0;
}
