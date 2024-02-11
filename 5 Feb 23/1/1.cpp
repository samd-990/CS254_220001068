#include <iostream>
#include <vector>
using namespace std;

void dfs(int i , int j , vector<vector<char>>& grid) {

    grid[i][j] = '2';
    int n = grid.size();
    int m = grid[0].size();

    if (i - 1 >= 0 && grid[i - 1][j] == '1')
        dfs(i - 1 , j , grid);

    if (i + 1 < n && grid[i + 1][j] == '1')
        dfs(i + 1 , j , grid);

    if (j - 1 >= 0 && grid[i][j - 1] == '1')
        dfs(i , j - 1 , grid);

    if (j + 1 < m && grid[i][j + 1] == '1')
        dfs(i , j + 1 , grid);
}

int regions(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '1') {
                ans++;
                dfs(i , j , grid);
            }
        }
    }
    return ans;
}


int main() {
    int n , m;
    cin >> n >> m;

    vector<vector<char>> grid(n , vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    cout << regions(grid) << '\n';

}