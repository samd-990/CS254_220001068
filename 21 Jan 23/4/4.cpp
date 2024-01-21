#include<iostream>
#include<algorithm>
using namespace std;

void QuickSort(int a[] , int start , int end) {
    if (start >= end)
        return;

    int pivot = (start + end) / 2;

    swap(a[pivot] , a[end]);

    int l = start , r = start;
    while (r < end) {
        if (a[r] <= a[end]) {
            swap(a[l] , a[r]);
            l++;
        }
        r++;
    }
    swap(a[l] , a[end]);
    QuickSort(a , start , l - 1);
    QuickSort(a , l + 1 , end);
}

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

        QuickSort(a , 0 , n - 1);

        if (n % 2) {
            cout << a[n / 2] << '\n';
        }
        else {
            cout << ((double)a[n / 2] + a[n / 2 + 1]) / 2 << '\n';
        }

    }
}