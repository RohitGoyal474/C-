
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
    vector<vector<int>>adj(n+1,vector<int>());
    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        adj[x].push_back(i);
    }
    for(int i=1;i<=n;i++){
        if(adj[i].size()==0)continue;
        else{
            int cnt=0;
            for(auto x:adj[i]){
                if(adj[x].size()==0)cnt++;
            }
            if(cnt<3){
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    cout<<"YES"<<endl;
    return 0;
}
