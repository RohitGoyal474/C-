
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

    int n=s1.size();
    int m=s2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<n;i++){
        dp[i][m]=n-i;
    }
    for(int j=0;j<m;j++){
        dp[n][j]=m-j;
    }
    dp[n][m]=0;
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
           int skip=1e9;
           if(s1[i]==s2[j]) skip=dp[i+1][j+1];
            // add one element
           int  add=1+dp[i][j+1];
           int remove=1+dp[i+1][j];
           int replace=1+dp[i+1][j+1];

           dp[i][j]=min(min(add,remove),min(replace,skip));

        }
    }
    cout<<dp[0][0]<<endl;
    

    return 0;
}
