#include<iostream>
#include<algorithm>
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

        // Insertion Sort 

        for (int i = 1; i < n; i++) {
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