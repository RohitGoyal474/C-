
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
    int n;
    cin>>n;
    vector<int>arr(n+1);
    for(int i=1;i<=n;i++)cin>>arr[i];
    vector<int>dp(n+1);
    // base case
    dp[n]=1;
    for(int i=n-1;i>=1;i--){
        int take=1;
        for(int k=2*i;k<=n;k+=i){
            if(arr[k]>arr[i]){
                take=max(take,1+dp[k]);
            }
        }
        
        dp[i]=take;

    }
    int result = *max_element(dp.begin() + 1, dp.end());
    cout << result << endl;
}


int main() {
    
    int noOfCases;
    cin>>noOfCases;
    while(noOfCases--){
        solve();
    }

    return 0;
}
