#include<bits/stdc++.h>
using namespace std;

void dfs(int node , int n , int vis , vector<vector<int>> arr[] , int pathsum , int prevcol , int& ans , vector<vector<int>>& edges , vector<vector<int>>& path) {
    if (vis == (1 << n) - 1) {
        if (pathsum < ans) {
            ans = pathsum;
            edges = path;
        }
        return;
    }

    for (auto v : arr[node]) {
        int adj = v[0];
        int w = v[1];
        int col = v[2];

        if (col == prevcol || (vis & (1 << adj)))
            continue;

        path.push_back({ adj, w, col });
        dfs(adj , n , vis | (1 << adj) , arr , pathsum + w , col , ans , edges , path);
        path.pop_back();
    }
}

void MinCost(int n , vector<vector<int>> arr[] , int& ans , vector<vector<int>>& edges) {
    for (int i = 0; i < n; i++) {
        vector<vector<int>> path = {};
        dfs(i , n , 1 << i , arr , 0 , -1 , ans , edges , path);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n , m;
        cin >> n >> m;

        vector<vector<int>> arr[n];

        for (int i = 0; i < m; i++) {
            int u , v , w , c;
            cin >> u >> v >> w >> c;
            arr[u].push_back({ v,w,c });
            arr[v].push_back({ u,w,c });
        }

        int ans = 1e9;
        vector<vector<int>> edges;

        MinCost(n , arr , ans , edges);
        cout << "Total weight of MST: ";
        cout << ans << '\n';
        cout << "Selected Edges: \n";
        for (auto i : edges) {
            cout << i[0] << ' ' << i[1] << '\n';
        }
    }
}
