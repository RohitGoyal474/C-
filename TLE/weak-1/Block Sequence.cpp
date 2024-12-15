
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
// #define rep(i, a, b) for (int i = a; i < b; ++i)

void solve(){
    int n;
    cin>>n;
    vector<int>b(n);
    for(int i=0;i<n;i++)cin>>b[i];
    vector<int>dp(n+1);
    dp[n]=0;
    for(int i=n-1;i>=0;i--){
        int pick=1e9;
        if(i+1+b[i]<=n)pick=dp[1+i+b[i]];
        int not_pick=1+dp[i+1];
        dp[i]=min(pick,not_pick);
    }
    cout<<dp[0]<<endl;
}
// dp[i]=min no of opp req to make 0 -i block beautiful;




int main() {
    
    int noOfCases;
    cin>>noOfCases;
    while(noOfCases--){
        solve();
    }

    return 0;
}
