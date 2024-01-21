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

        int c[n + m];

        int ap = 0 , bp = 0;
        int cp = 0;

        while (ap < n && bp < m) {
            if (a[ap] < b[bp]) {
                c[cp] = a[ap];
                cp++;
                ap++;
            }

            else {
                c[cp] = b[bp];
                cp++;
                bp++;
            }
        }

        while (ap < n) {
            c[cp] = a[ap];
            cp++;
            ap++;
        }

        while (bp < m) {
            c[cp] = b[bp];
            cp++;
            bp++;
        }

        for (int i = 0; i < n + m; i++) {
            cout << c[i] << ' ';
        }
    }

    return 0;
}