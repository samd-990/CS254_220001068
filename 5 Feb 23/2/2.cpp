#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int snakeandladder(vector<vector<int>>& board) {
    queue<int> q;
    q.push(1);
    int n = board.size();
    int m = board[0].size();
    int goal = n * m;
    vector<int> dist(goal + 1 , 1e9);
    dist[1] = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        if (curr == goal)
            break;

        for (int i = 1; i <= 6; i++) {
            int next = i + curr;
            if (next > goal)
                continue;
            int r = (next - 1) / m , c = (next - 1) % m;
            int& vertex = board[n - 1 - r][r % 2 == 0 ? c : m - 1 - c];
            if (vertex != 0) {
                next = (vertex > 0 ? vertex : next);
                dist[next] = min(dist[next] , dist[curr] + 1);
                q.push(next);
                vertex = 0;
            }
        }
    }
    return (dist[goal] == 1e9 ? -1 : dist[goal]);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n , m;
        cin >> n >> m;
        vector<vector<int>> grid(n , vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        cout << snakeandladder(grid) << '\n';
    }
}