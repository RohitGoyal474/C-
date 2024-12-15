
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
#include <climits>
#include <iomanip>
using namespace std;

int main() {
    int n,x;
    cin>>n>>x;
    vector<int>coin(n);
    for(int i=0;i<n;i++)cin>>coin[i];
    vector<int>dp(x+1,1e9);
    dp[0]=0;
    for(int i=1;i<=x;i++){
        for(auto m:coin){
            if(i>=m){
                dp[i]=min(dp[i],dp[i-m]+1);
            }
        }
    }
    if(dp[x]==1e9)cout<<-1<<endl;
    else cout<< dp[x];
    
    

    return 0;
}
