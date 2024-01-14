#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int main() {
	int n , x;
	cin >> n >> x;

	int h[n] , s[n];

	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	vector<vector<int>> dp(n , vector<int>(x + 1 , 0));

	if (h[0] <= x) {
		dp[0][h[0]] = s[0];
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < x + 1; j++) {
			if (j - h[i] >= 0)
				dp[i][j] = max(dp[i - 1][j] , j == h[i] ? s[i] : dp[i - 1][j - h[i]] + s[i]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	cout << *max_element(dp[n - 1].begin() , dp[n - 1].end()) << '\n';


	return 0;
}
