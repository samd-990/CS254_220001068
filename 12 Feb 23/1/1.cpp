#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void TopoSort(vector<int> adj[] , int n) {
    vector<int> parent(n , 0);
    vector<bool> vis(n , false);

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
        cout << t << ' ';
        q.pop();
    }

    cout << '\n';
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

        TopoSort(adj , n);
    }

    return 0;
}