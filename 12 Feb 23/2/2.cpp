#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> TopoSort(vector<int> adj[] , int n) {
    vector<int> parent(n , 0);
    vector<bool> vis(n , false);
    vector<int> ans;

    for (int i = 0; i < n; i++) {
        for (int& j : adj[i]) {
            parent[j]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < n; i++) {
        if (parent[i] == 0) {
            q.push(i);
        }
    }


    while (!q.empty()) {
        int t = q.front();
        for (int& j : adj[t]) {
            if (!vis[j]) {
                parent[j]--;
                if (parent[j] == 0)
                    q.push(j);
            }
        }

        vis[t] = true;
        ans.push_back(t);
        q.pop();
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

        vector<int> res = TopoSort(adj , n);

        vector<int> dist(n , 0);
        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int& j : adj[res[i]]) {
                dist[res[i]] = max(dist[res[i]] , 1 + dist[j]);
            }
            ans = max(ans , dist[i]);
        }

        cout << ans << '\n';
    }

    return 0;
}