
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
    int n,x;
    cin>>n>>x;
    int mod=1e9+7;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>dp(x+1,0);
    dp[0]=1;
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(i>=arr[j]){
                dp[i]=(dp[i]+dp[i-arr[j]])%mod;
            }
        }
    }
    cout<<dp[x]<<endl;  
    

    return 0;
}
