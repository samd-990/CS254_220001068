#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int tsp(int n , int curr , int start , int pathdist , int vis , vector<vector<int>>& dist) {
    int ans = INT_MAX;
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if ((vis & (1 << i)) == 0) {
            flag = false;
            ans = min(dist[curr][i] +
                tsp(
                    n ,
                    i ,
                    start ,
                    pathdist + dist[curr][i] ,
                    (vis | (1 << i)) ,
                    dist
                ) ,
                ans
            );
        }
    }

    if (flag)
        return dist[curr][start];
    else
        return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> dist(n + 1 , vector<int>(n + 1));

        for (int i = 0; i < (n * (n - 1) / 2); i++) {
            int a , b , d;
            cin >> a >> b >> d;

            dist[a][b] = d;
            dist[b][a] = d;
        }

        cout << tsp(n , 1 , 1 , 0 , 2 , dist) << '\n';
    }

    return 0;
}

// 4
// 1 2 20
// 1 3 42
// 1 4 35
// 2 3 30
// 2 4 34
// 3 4 12

// 4
// 1 2 10
// 1 3 15
// 1 4 20
// 2 3 35
// 2 4 25
// 3 4 30