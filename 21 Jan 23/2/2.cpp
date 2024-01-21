#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;

    while (t--) {
        int n , m;
        cin >> n >> m;

        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // Insertion Sort starting from index m + 1

        for (int i = m - 1; i < n; i++) {
            int j = i - 1;
            while (j >= 0 && a[j] > a[j + 1]) {
                swap(a[j] , a[j + 1]);
                j--;
            }
        }

        for (int i = 0; i < n; i++) {
            cout << a[i] << ' ';
        }
        cout << '\n';

    }
}