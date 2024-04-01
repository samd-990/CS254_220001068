#include<bits\stdc++.h>
#define int long long
using namespace std;

pair<int , vector<int>> max_profit_unoptimized(int n , vector<vector<int>>& jobs) {
    int max_deadline = 0;
    for (int i = 0; i < n; i++) {
        max_deadline = max(max_deadline , jobs[i][1]);
    }

    int deadl[max_deadline + 1];
    for (int i = 0; i <= max_deadline; i++) {
        deadl[i] = -1;
    }

    sort(jobs.begin() , jobs.end() ,
        [&](const vector<int>& a , const vector<int>& b) {
            return a[2] > b[2];
        }
    );

    vector<int> ans;
    int total = 0;

    for (auto& v : jobs) {
        int i = v[1];
        while (deadl[i] != -1 && i != 0) i--;
        if (i != 0) {
            deadl[i] = v[2];
            total += v[2];
            ans.push_back(v[0]);
        }
    }

    return { total, ans };
}

pair<int , vector<int>> max_profit_optimized(int n , vector<vector<int>>& jobs) {
    int max_deadline = 0;
    for (int i = 0; i < n; i++) {
        max_deadline = max(max_deadline , jobs[i][1]);
    }

    sort(jobs.begin() , jobs.end() ,
        [](const vector<int>& a , const vector<int>& b) {
            return a[2] > b[2];
        }
    );

    vector<int> ans;
    int total = 0;

    set<int> st;
    for (int i = 1; i <= max_deadline; i++) {
        st.insert(i);
    }

    for (auto& v : jobs) {
        auto it = st.upper_bound(v[1]);
        if (it != st.begin()) {
            it--;
            st.erase(*it);
            ans.push_back(v[0]);
            total += v[2];
        }
    }

    return { total, ans };
}

int32_t main() {
    int n;
    cin >> n;

    vector<vector<int>> jobs(n , vector<int>(3));
    for (int i = 0; i < n; i++) {
        cin >> jobs[i][0] >> jobs[i][1] >> jobs[i][2];
    }


    auto p1 = max_profit_unoptimized(n , jobs);
    auto p2 = max_profit_optimized(n , jobs);

    cout << "Greedy Unoptimized O(N * M): \n";
    cout << "Maximum Profit: " << p1.first << '\n';
    cout << "Jobs taken: ";
    for (auto i : p1.second) cout << i << ' ';
    cout << '\n';

    cout << "Greedy Optimized O(Nlog(N) + Nlog(M)): \n";
    cout << "Maximum Profit: " << p2.first << '\n';
    cout << "Jobs taken: ";
    for (auto i : p2.second) cout << i << ' ';
    cout << '\n';

}

// 4
// 1 4 20
// 2 1 10
// 3 1 40 
// 4 1 30