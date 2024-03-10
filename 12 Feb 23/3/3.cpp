#include <bits/stdc++.h>
using namespace std;

void num_scc(vector<int> adj[] , int n) {
    vector<int> exit_time;
    vector<bool> vis(n , false);

    function<void(int)> dfs_exit_time = [&](int node)
        {
            vis[node] = true;
            for (int j : adj[node]) {
                if (!vis[j]) {
                    dfs_exit_time(j);
                }
            }
            exit_time.push_back(node);
        };

    for (int i = 0; i < n; i++) {
        if (!vis[i]) dfs_exit_time(i);
    }

    // Transpose
    vector<int> adj_t[n];
    for (int i = 0; i < n; i++) {
        for (int j : adj[i]) {
            adj_t[j].push_back(i);
        }
    }

    fill(vis.begin() , vis.end() , false);
    vector<vector<int>> ans;

    function<void(int)> dfs_scc = [&](int node)
        {
            ans.back().push_back(node);
            vis[node] = true;
            for (int j : adj_t[node]) {
                if (!vis[j]) {
                    vis[j] = true;
                    dfs_scc(j);
                }
            }
        };


    while (!exit_time.empty()) {
        int t = exit_time.back();
        exit_time.pop_back();
        if (!vis[t]) {
            ans.push_back({});
            dfs_scc(t);
        }
    }

    cout << "Number of strongly connected components: " << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
        cout << "Component " << i + 1 << ": ";
        for (int j : ans[i]) {
            cout << j << ' ';
        }
        cout << '\n';
    }

}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n , m;
        cin >> n >> m;

        vector<int> adj[n];

        for (int i = 0; i < m; i++) {
            int a , b;
            cin >> a >> b;
            adj[a].push_back(b);
        }

        num_scc(adj , n);
    }

    return 0;
}