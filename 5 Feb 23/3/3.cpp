#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(vector<vector<int>>& adj , int src) {
    int n = adj.size();
    int color[n];
    for (int i = 0; i < n; ++i)
        color[i] = -1;

    color[src] = 1;

    queue<int> q;
    q.push(src);

    while (!q.empty()) {
        int u = q.front();
        q.pop();


        for (int v = 0; v < n; ++v) {
            if (v == u)
                continue;

            if (adj[u][v] && color[v] == -1) {
                color[v] = 1 - color[u];
                q.push(v);
            }


            else if (adj[u][v] && color[v] == color[u])
                return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n , vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
            adj[i][j] = !(adj[i][j]);
        }
    }

    cout << (isBipartite(adj , 1) ? "YES\n" : "NO\n");

}