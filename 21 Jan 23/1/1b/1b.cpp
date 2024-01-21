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
            if (a[i] < b[j]) {
                c.push_back(a[i]);
                i++;

                while (i < n && a[i - 1] == a[i]) {
                    i++;
                }
            }

            else if (a[i] > b[j]) {
                c.push_back(b[j]);
                j++;

                while (j < m && b[j - 1] == b[j]) {
                    j++;
                }
            }

            else {
                c.push_back(a[i]);
                i++;
                j++;

                while (i < n && a[i - 1] == a[i]) {
                    i++;
                }

                while (j < m && b[j - 1] == b[j]) {
                    j++;
                }
            }
        }

        while (i < n) {
            c.push_back(a[i]);
            i++;

            while (i < n && a[i - 1] == a[i]) {
                i++;
            }
        }

        while (j < m) {
            c.push_back(b[j]);
            j++;

            while (j < m && b[j - 1] == b[j]) {
                j++;
            }
        }

        for (int& i : c) {
            cout << i << ' ';
        }
        cout << '\n';
    }

    return 0;
}