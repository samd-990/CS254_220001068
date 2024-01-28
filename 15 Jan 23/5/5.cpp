// Samyak Dhyani
// 220001068

#include<iostream>
#include<cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int min1 = min(a[0] , a[1]);
        int min2 = max(a[0] , a[1]);

        for (int i = 2; i < n; i++) {
            if (a[i] <= min1) {
                min2 = min1;
                min1 = a[i];
            }
            else if (a[i] <= min2) {
                min2 = a[i];
            }
        }

        cout << "The two minimas are " << min1 << " and " << min2 << '\n';
    }
}