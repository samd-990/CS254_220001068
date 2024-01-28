#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int MaxSubarraySum(vector<int>& a) {
    int n = a.size();

    // finding power of 2 which is >= n
    int x = 31 - __builtin_clz(n);
    if (n != (1 << x))
        x++;

    int size = (1 << x);

    vector<vector<int>> tree(2 * size - 1 , vector<int>(4 , 0));

    for (int i = 0; i < a.size(); i++) {
        tree[size - 1 + i][0] = max(0 , a[i]);  // max subarray
        tree[size - 1 + i][1] = max(0 , a[i]);  // max prefix sum
        tree[size - 1 + i][2] = max(0 , a[i]);  // max suffix sum
        tree[size - 1 + i][3] = a[i];           // total sum
    }

    for (int i = size - 2; i >= 0; i--) {
        tree[i][0] = max({
            tree[2 * i + 1][0],
            tree[2 * i + 2][0],
            tree[2 * i + 1][2] + tree[2 * i + 2][1]
            }
        );

        tree[i][1] = max(
            tree[2 * i + 1][1] ,
            tree[2 * i + 1][3] + tree[2 * i + 2][1]
        );

        tree[i][2] = max(
            tree[2 * i + 2][2] ,
            tree[2 * i + 1][2] + tree[2 * i + 2][3]
        );

        tree[i][3] = tree[2 * i + 1][3] + tree[2 * i + 2][3];
    }

    return tree[0][0];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int& i : a) {
            cin >> i;
        }

        cout << MaxSubarraySum(a) << '\n';
    }

    return 0;
}