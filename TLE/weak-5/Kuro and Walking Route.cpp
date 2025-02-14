#include <iostream>
#include <vector>

using namespace std;

vector<int> in, out, child_cnt;
int timer = 0;

void dfs(int node, int parent, vector<vector<int>> &adj) {
    timer++;
    in[node] = timer;
    child_cnt[node] = 1;
    for (auto child : adj[node]) {
        if (child == parent) continue;
        dfs(child, node, adj);
        child_cnt[node] += child_cnt[child];
    }
    out[node] = timer; // Move this after processing all children
}

int find_z(int x, int y, vector<vector<int>> &adj) {
    for (auto child : adj[y]) {
        if (in[x] >= in[child] && out[x] <= out[child]) {
            return child;
        }
    }
    return 0;  // Return y itself if no valid child is found
}

int main() {
    int n, x, y;
    cin >> n >> x >> y;

    vector<vector<int>> adj(n + 1);
    in.resize(n + 1, 0);
    out.resize(n + 1, 0);
    child_cnt.resize(n + 1, 0);

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0, adj);

    long long ans = 1LL * n * (n - 1);
    
    if (x == y) {  // Handle case where x == y
        cout << ans << endl;
        return 0;
    }
    
    int z = find_z(x, y, adj);
    int val=n;
    val-=child_cnt[x];
    ans -= 1LL * child_cnt[x] * val;

    cout << ans << endl;
    return 0;
}
