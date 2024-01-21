// Samyak Dhyani
// 220001068

#include <bits/stdc++.h> 
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n , m;
        cin >> n >> m;

        int a[n] , b[m];

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];

        vector<int> c;

        int i = 0 , j = 0;

        while (i < n && j < m) {
            if (a[i] == b[j]) {
                c.push_back(a[i]);
            }

            if (a[i] <= b[j]) {
                i++;
                while (i < n && a[i - 1] == a[i]) {
                    i++;
                }
            }

            else {
                j++;
                while (j < m && b[j - 1] == b[j]) {
                    j++;
                }
            }
        }

        for (auto it : c) {
            cout << it << " ";
        }
        cout << '\n';
    }
}