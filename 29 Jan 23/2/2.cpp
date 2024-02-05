#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

double MedianSortedArrays(vector<int>& nums1 , vector<int>& nums2) {
    int sz1 = nums1.size() , sz2 = nums2.size();
    int half = ((sz1 + sz2) >> 1);

    vector<int>& a = nums1 , & b = nums2;

    if (sz2 > sz1) {
        swap(a , b);
        swap(sz1 , sz2);
    }
    if (sz2 == sz1) {
        if (nums1.back() <= nums2[0]) {
            return ((double)nums1.back() + nums2[0]) / 2;
        }
        else if (nums1[0] >= nums2.back()) {
            return ((double)nums1[0] + nums2.back()) / 2;
        }
    }

    if (sz2 == 0) {
        if (sz1 & 1) {
            return a[sz1 / 2];
        }
        else {
            return ((double)a[sz1 / 2 - 1] + a[sz1 / 2]) / 2;
        }
    }

    if (nums1.back() <= nums2[0]) {
        if ((sz1 + sz2) & 1) {
            return nums1[half];
        }
        else {
            return (1.0 * nums1[half - 1] + nums1[half]) / 2;
        }
    }
    else if (nums1[0] >= nums2.back()) {
        if ((sz1 + sz2) & 1) {
            return nums1[half - sz2];
        }
        else {
            return (1.0 * nums1[half - sz2 - 1] + nums1[half - sz2]) / 2;
        }
    }

    int l = 0 , r = sz1 , mid;

    while (r - l > 1) {
        mid = (l + r) / 2;
        int in = upper_bound(b.begin() , b.end() , a[mid]) - b.begin();
        if (mid + 1 + in > half) {
            r = mid;
        }
        else {
            l = mid;
        }
    }

    int lreq = half - l - 1;
    int lnum , rnum;

    if (sz2 == lreq) {
        lnum = max(a[l] , b.back());
        rnum = a[r];
    }
    else if (lreq == 0) {
        lnum = a[l];
        rnum = min(a[r] , b[0]);
    }
    else {
        lnum = max(a[l] , b[lreq - 1]);
        rnum = min(a[r] , b[lreq]);
    }

    if ((sz1 + sz2) & 1) {
        return rnum;
    }
    else {
        return ((double)lnum + rnum) / 2;
    }

}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n , m;
        cin >> n >> m;

        vector<int> v1(n) , v2(m);

        for (int& i : v1) {
            cin >> i;
        }

        for (int& i : v2) {
            cin >> i;
        }

        cout << fixed << setprecision(6) << MedianSortedArrays(v1 , v2) << '\n';
    }

    return 0;
}