#include <bits/stdc++.h>
using namespace std;

//Shortcut
#define fp(i, l, r)     for(i = l; i < r; i++)
#define ms(x, y)        memset(x, y, sizeof(x))
#define all(x)          x.begin(), x.end()
#define sc              second
#define fr              first
#define el              '\n'

using dd                = double;
using ll                = long long;
using ull               = unsigned long long;
using pii               = pair<int, int>;
using pll               = pair<ll, ll>;

// Global variabel
const int S = 1e5,
minf = INT_MIN, 
pinf = INT_MAX;

// Fren -> Not, Equal, AND, OR
// ASCII 0 = 48, A = 65, a = 97

int n, q, a, b, i, dis;
vector<vector<int>> adj, par;
vector<int> depth;

void dfs(int node = 1, int parent = 0) {
    for(int &child : adj[node]) {
        if(child != parent) {
            depth[child] = depth[node] + 1;
            par[child][0] = node;
            for(i = 1; i <= (int)log2(n); i++) 
                par[child][i] = par[par[child][i - 1]][i - 1];
            dfs(child, node);
        }
    }
}

int lca(int node1, int node2) {
    if(depth[node1] < depth[node2])
        swap(node1, node2);

    for(i = log2(n); i >= 0; i--) 
        if((depth[node1] - depth[node2]) & (1 << i))
            node1 = par[node1][i];
    if(node1 == node2) return node1;

    for(i = log2(n); i >= 0; i--) {
        if(par[node1][i] != par[node2][i]) {
            node1 = par[node1][i];
            node2 = par[node2][i];
        }
    }
    return par[node1][0];
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    cin >> n >> q;
    adj.resize(n + 1);
    depth.resize(n + 1);
    par.resize(n + 1, vector<int> ((int)log2(n) + 1, 0));

    for(i = 1; i < n; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs();

    while(q--) {
        cin >> a >> b;
        dis = lca(a, b);
        cout << depth[a] + depth[b] - depth[dis] * 2<< el;
    }
    
    return 0;
}