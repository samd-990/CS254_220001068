#include <iostream>
#include <queue>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n , k;
        cin >> n >> k;
        priority_queue<int> pq;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            pq.push(x);
        }

        for (int i = 0; i < k - 1; i++) {
            pq.pop();
        }

        cout << pq.top() << '\n';

    }
    return 0;
}