#include<bits/stdc++.h>
using namespace std;
#define ll long long

class DisjointSetUnion {
    private:
    static const int dsu_N = 1e5 + 10;
    int parent[dsu_N];  //Stores parent node of the connected components
    int sz[dsu_N];      //Stores size of connected components
    int max_size;       //Shows the maximum component size
    int conn_comp;      //Shows the number of connected components

    public:
    int find(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find(parent[v]);
    }
    DisjointSetUnion() {
        max_size = 0;
        conn_comp = 0;
    }

    void make(int v) {
        parent[v] = v;
        sz[v] = 1;
        conn_comp++;
        max_size = max(max_size , 1);
    }

    void Union(int a , int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (sz[a] < sz[b]) {
                std::swap(a , b);
            }
            parent[b] = a;
            sz[a] += sz[b];
            max_size = max(max_size , sz[a]);
            conn_comp--;
        }
    }
    int get_max_size() {
        return max_size;
    }
    int get_conn_comp() {
        return conn_comp;
    }
};

struct Edge {
    int id;
    int wt;
    int u;
    int v;

    Edge(const int& id , const int& wt , const int& u , const int& v) {
        this->id = id;
        this->wt = wt;
        this->u = u;
        this->v = v;
    }
};

int main() {
    int n , m; cin >> n >> m;
    map<int , int> present;
    DisjointSetUnion dsu;
    vector<Edge> edges;
    int id = 1;
    for (int i = 0; i < m; i++) {
        int a , b , c;
        cin >> a >> b >> c;
        edges.push_back(Edge(id , c , a , b));
        id++;
    }
    sort(edges.begin() , edges.end() ,
        [](const Edge& edge1 , const Edge& edge2) {
            return edge1.wt < edge2.wt;
        }
    );
    for (int i = 1; i <= n; i++) {
        dsu.make(i);
    }
    int total_cost = 0;
    for (auto& edge : edges) {
        int wt = edge.wt;
        int u = edge.u;
        int v = edge.v;

        if (dsu.find(u) == dsu.find(v)) continue;
        dsu.Union(u , v);
        total_cost += wt;
        present[edge.id] = 1;
    }
    cout << "Best cost: " << total_cost << endl;
    int sec_best_cost = INT_MAX;
    vector<int> sec_best_MST;
    for (auto edge : edges) {
        if (present.find(edge.id) == present.end()) {
            continue;
        }
        DisjointSetUnion d;
        for (int i = 1; i <= n; i++) {
            d.make(i);
        }
        int cost = 0;
        vector<int> mst;
        for (auto e : edges) {
            if (e.id == edge.id) continue;
            int wt = e.wt;
            int u = e.u;
            int v = e.v;
            if (d.find(u) == d.find(v)) continue;
            d.Union(u , v);
            mst.push_back(e.id);
            cost += wt;
        }
        bool isMST = true;
        int comp_one = d.find(1);
        for (int i = 2; i <= n; i++) {
            if (comp_one != d.find(i)) {
                isMST = false;
                break;
            }
        }
        if (cost < sec_best_cost && isMST) {
            sec_best_cost = cost;
            sec_best_MST = mst;
        }
        mst.clear();
        cost = 0;
    }
    cout << "Second best cost: " << sec_best_cost << endl;
    cout << "Edge id's in second best MSTs are: ";
    for (auto i : sec_best_MST) {
        cout << i << " ";
    } cout << endl;
    int comp_one = dsu.find(1);
    for (int i = 2; i <= n; i++) {
        if (comp_one != dsu.find(i)) {
            cout << "IMPOSSIBLE" << endl;
            break;
        }
    }
    return 0;
}