
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
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.size(),m=s2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(s1[i]==s2[j]){
                dp[i][j]=dp[i+1][j+1]+1;
            }
            else{
                dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
            }
        }
    }
    cout<<dp[0][0];
    return 0;
}
