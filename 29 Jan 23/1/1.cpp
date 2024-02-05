#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Merge(vector<int>& v , int l , int mid , int r , long long& ans) {
    vector<int> buffer(r - l);
    int p1 = l , p2 = mid , p = 0;
    while (p1 != mid && p2 != r) {
        if (v[p1] <= v[p2]) {
            ans += p2 - mid;
            buffer[p++] = v[p1++];

        }
        else {
            ans += mid - p1;
            buffer[p++] = v[p2++];
        }
    }

    while (p1 != mid) {
        buffer[p++] = v[p1++];
        ans += r - mid;
    }

    while (p2 != r)
        buffer[p++] = v[p2++];

    for (long long i = 0; i < r - l; i++) {
        v[l + i] = buffer[i];
    }
}

void MergeSort(vector<int>& v , int l , int r , long long& ans) {
    if (r - l <= 1)
        return;
    int mid = l + (r - l) / 2;
    MergeSort(v , l , mid , ans);
    MergeSort(v , mid , r , ans);
    Merge(v , l , mid , r , ans);
}

long long inversions(vector<int>& v) {
    long long ans = 0;
    MergeSort(v , 0 , v.size() , ans);

    return ans / 2;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);

        for (int& i : v) {
            cin >> i;
        }

        cout << inversions(v) << '\n';
    }

    return 0;
}