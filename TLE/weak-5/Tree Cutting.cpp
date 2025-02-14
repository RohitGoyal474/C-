#include <iostream>
#include <vector>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; ++i)

void dfs(int node, vector<vector<int>>& adj, int mid, int& no_of_components, vector<int>& weight) {
    weight[node] = 1;  // Each node has at least weight 1 (itself)
    
    for (auto child : adj[node]) {
        dfs(child, adj, mid, no_of_components, weight);
        weight[node] += weight[child];
    }

    if (node == 1) {  // Root node special case
        if (weight[node] < mid) {
            no_of_components--;
        }
    } else {
        if (weight[node] >= mid) {
            no_of_components++;
            weight[node] = 0;  // Reset weight after forming a component
        }
    }
}

bool isValid(int n, int k, vector<vector<int>>& adj, int mid) {
    vector<int> weight(n + 1, 0);
    int no_of_components = 0;
    dfs(1, adj, mid, no_of_components, weight);
    return no_of_components >= k;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n + 1);

    for (int i = 1; i < n; i++) {  // Since it's a tree, n-1 edges
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    int s = 1, x = n, ans = 1;
    while (s <= x) {
        int mid = (s + x) / 2;
        if (isValid(n, k, adj, mid)) {
            ans = mid;
            s = mid + 1;
        } else {
            x = mid - 1;
        }
    }

    cout << ans << endl;
}

int main() {
    int noOfCases;
    cin >> noOfCases;
    while (noOfCases--) {
        solve();
    }
    return 0;
}
