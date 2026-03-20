#include <bits/stdc++.h>
using namespace std;

vector<int> parent, sz;
int maxi;
int components;

int findultpar(int node) {
    if (node == parent[node])
        return node;
    return parent[node] = findultpar(parent[node]);
}

void unionbysize(int u, int v) {
    int ulpu = findultpar(u);
    int ulpv = findultpar(v);

    if (ulpu == ulpv) return;

    if (sz[ulpu] < sz[ulpv]) {
        parent[ulpu] = ulpv;
        sz[ulpv] += sz[ulpu];
        maxi = max(maxi, sz[ulpv]);
    } else {
        parent[ulpv] = ulpu;
        sz[ulpu] += sz[ulpv];
        maxi = max(maxi, sz[ulpu]);
    }
    components--;
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;

    parent.resize(nodes+1);
    sz.resize(nodes+1, 1);

    components = nodes;
    maxi = 1;

    for (int i = 0; i < nodes+1; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        unionbysize(u, v);
    }

    int a, b;
    cin >> a >> b;

    if (findultpar(a) == findultpar(b))
        cout << "Connected aaah!";
    else
        cout << "Meeeh not Connected biach!";

    return 0;
}