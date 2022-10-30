#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int,int>;
using vi = vector<int>;

struct DSU {

    int n = 0;
    vector<int> parent;
    vector<int> sz;

    DSU(int nn){
        n = nn;
        sz.assign(n + 5, 1);
        parent.assign(n + 5, 0);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x){
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]); 
    }

    void join(int a, int b){
        a = find(a); b = find(b);
        if(a == b) return;
        if(sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }   
};
