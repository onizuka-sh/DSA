#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, size;
    int components;

    DSU(int n) {
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        components = n;
        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        components--;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int,int>> edges(m);
    for (int i = 0; i < m; i++)
        cin >> edges[i].first >> edges[i].second;

    vector<pair<int,int>> queries(k);
    set<pair<int,int>> removed;

    for (int i = 0; i < k; i++) {
        cin >> queries[i].first >> queries[i].second;
        if (queries[i].first > queries[i].second)
            swap(queries[i].first, queries[i].second);
        removed.insert(queries[i]);
    }

    DSU dsu(n);

    // Add all edges that are NOT removed
    for (auto &e : edges) {
        int a = e.first, b = e.second;
        if (a > b) swap(a, b);
        if (!removed.count({a, b}))
            dsu.unite(a, b);
    }

    vector<int> ans;

    // Process queries in reverse
    for (int i = k - 1; i >= 0; i--) {
        ans.push_back(dsu.components);
        dsu.unite(queries[i].first, queries[i].second);
    }

    reverse(ans.begin(), ans.end());

    for (int x : ans)
        cout << x << " ";

    return 0;
}