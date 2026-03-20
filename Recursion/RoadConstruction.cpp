#include <bits/stdc++.h>
using namespace std;

vector<int> parent, sz;
int components, maxi;

int findultpar(int node) {
    if (node == parent[node]) return node;
    return parent[node] = findultpar(parent[node]);
}

void unionbysize(int u, int v) {
    int pu = findultpar(u);
    int pv = findultpar(v);

    if (pu == pv) return;

    if (sz[pu] < sz[pv]) {
        parent[pu] = pv;
        sz[pv] += sz[pu];
        maxi = max(maxi, sz[pv]);
    } else {
        parent[pv] = pu;
        sz[pu] += sz[pv];
        maxi = max(maxi, sz[pu]);
    }
    components--;
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;

    parent.resize(nodes + 1);
    sz.resize(nodes + 1, 1);

    components = nodes;
    maxi = 1;

    for (int i = 1; i <= nodes; i++)
        parent[i] = i;

    while (edges--) {
        int u, v;
        cin >> u >> v;
        unionbysize(u, v);
        cout << components << " " << maxi << "\n";
    }

    return 0;
}