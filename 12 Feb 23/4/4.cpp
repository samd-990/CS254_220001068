#include <iostream>
#include <vector>
using namespace std;

bool dfscycle(vector<int> adj[] , int n , int src , vector<bool>& vis , vector<bool>& dfs) {
    bool ans = false;
    for (int j : adj[src]) {
        if (dfs[j]) {
            return true;
        }
        else if (!vis[j]) {
            vis[j] = true;
            dfs[j] = true;
            ans |= dfscycle(adj , n , j , vis , dfs);
            dfs[j] = false;
            if (ans)
                break;
        }
    }

    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n , m;
        cin >> n >> m;
        vector<int> adj[n];
        for (int i = 0; i < m; i++) {
            int u , v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        vector<bool> vis(n , false) , dfs(n , false);

        vis[0] = dfs[0] = true;
        bool ans = dfscycle(adj , n , 0 , vis , dfs);

        if (ans) {
            cout << "Cycle is present\n";
        }
        else {
            cout << "Cycle is not present\n";
        }
    }

    return 0;
}