#include <bits/stdc++.h>
using namespace std;

class DSU {
    public:
    vector<int> parent;
    DSU(const int& n) {
        parent.resize(n , -1);
    }

    void display() {
        for (int i = 0; i < parent.size(); i++) {
            cout << parent[i] << ' ';
        }
        cout << '\n';
    }

    void make_set(int num) {
        if (parent[num] == -1)
            parent[num] = num;
    }

    int get_parent(int a) {
        if (parent[a] != a) {
            parent[a] = get_parent(parent[a]);
        }
        return parent[a];
    }

    bool union_set(int a , int b) {
        if (get_parent(a) == get_parent(b))
            return false;
        parent[get_parent(b)] = parent[get_parent(a)];
        return true;
    }
};

vector<tuple<int , int , int>> Kruskal(int n , vector<tuple<int , int , int>> edges) {
    vector<tuple<int , int , int>> ans;

    sort(edges.begin() , edges.end() ,
        [](const tuple<int , int , int>& a , const tuple<int , int , int>& b) {
            return get<2>(a) < get<2>(b);
        }
    );

    DSU ds(n);

    for (auto& t : edges) {
        int u = get<0>(t);
        int v = get<1>(t);

        ds.make_set(u);
        ds.make_set(v);
        if (ds.union_set(u , v)) {
            ans.push_back(t);
        }
    }

    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n , m;
        cin >> n >> m;

        vector<tuple<int , int , int>> edges;

        for (int edge = 0; edge < m; edge++) {
            int u , v , w;
            cin >> u >> v >> w;

            edges.emplace_back(u , v , w);
        }
        vector<tuple<int , int , int>> res = Kruskal(n , edges);

        int total_weight = 0;
        cout << "Selected Edges of MST are: \n";

        for (auto& t : res) {
            cout << get<0>(t) << ' ' << get<1>(t) << ' ' << get<2>(t) << '\n';
            total_weight += get<2>(t);
        }

        cout << "Total weight of MST: " << total_weight << '\n';
    }
    return 0;
}
