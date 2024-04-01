#include <bits/stdc++.h>
#define int long long
using namespace std;

pair<int , vector<int>> optimal(int n , int w , int weight[] , int value[]) {
    int dp[n][w + 1];
    memset(dp , 0 , sizeof dp);

    dp[0][weight[0]] = value[0];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= w; j++) {
            dp[i][j] = dp[i - 1][j];

            if (j - weight[i] >= 0)
                dp[i][j] = max(dp[i][j] , dp[i - 1][j - weight[i]] + value[i]);
        }
    }

    int j = max_element(dp[n - 1] , dp[n - 1] + w + 1) - dp[n - 1];
    int tot = dp[n - 1][j];
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--) {
        if (i == 0 && dp[0][j])
            ans.push_back(i + 1);
        else if (dp[i][j] != dp[i - 1][j]) {
            ans.push_back(i + 1);
            j -= weight[i];
            if (j == 0)break;
        }
    }

    return { tot,ans };
}

pair<int , vector<int>> greedy(int n , int w , int weight[] , int value[]) {
    int ind[n];
    iota(ind , ind + n , 0);

    sort(ind , ind + n ,
        [&](const int& a , const int& b) {
            return (value[a] * weight[b] > value[b] * weight[a] || weight[a] < weight[b]);
        }
    );

    int tot = 0;
    int wgt = 0;
    vector<int> ans;

    for (int i = 0; i < n; i++) {
        if (weight[ind[i]] + wgt <= w) {
            ans.push_back(ind[i] + 1);
            wgt += weight[ind[i]];
            tot += value[ind[i]];
        }
    }

    return { tot,ans };
}

int32_t main() {
    int n , w;
    cin >> n >> w;

    int weight[n] , value[n];

    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }


    pair<int , vector<int>> p_optimal = optimal(n , w , weight , value);
    pair<int , vector<int>> p_greedy = greedy(n , w , weight , value);

    cout << "Greedy: \n";
    cout << "Total weight: " << p_greedy.first << '\n';
    cout << "Items included: ";
    for (int& i : p_greedy.second) cout << i << ' ';
    cout << '\n';

    cout << "Optimal (using DP): \n";
    cout << "Total weight: " << p_optimal.first << '\n';
    cout << "Items included: ";
    for (int& i : p_optimal.second) cout << i << ' ';
    cout << '\n';
}

// 5 10
// 2 5 7 3 1
// 10 20 15 7 5