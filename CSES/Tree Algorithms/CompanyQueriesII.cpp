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

int n, q, a, b, i;
vector<int> depth;
vector<vector<int>> adj, par;

void dfs(int node = 1) {
    for(int &child : adj[node]) {
        par[child][0] = node;
        depth[child] = depth[node] + 1;
        for(i = 1; i <= (int)log2(n); i++) 
            par[child][i] = par[par[child][i - 1]][i - 1]; 
        dfs(child);
    }
}

int lca(int n1, int n2) {
    if(depth[n1] < depth[n2])
        swap(n1, n2);

    for(i = log2(n); i >= 0; i--) 
        if((depth[n1] - depth[n2]) & (1 << i))  
            n1 = par[n1][i];
    if(n1 == n2) return n1;

    for(i = log2(n); i >= 0; i--) {
        if(par[n1][i] != par[n2][i]) {
            n1 = par[n1][i];
            n2 = par[n2][i];
        }
    }
    return par[n1][0];
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    cin >> n >> q;
    adj.resize(n + 1);
    depth.resize(n + 1);
    par.resize(n + 1, vector<int> ((int)log2(n) + 1, 0));

    depth[1] = 0;
    for(i = 2; i <= n; i++) {
        cin >> a;
        adj[a].push_back(i);
    }
    dfs();

    while(q--) {
        cin >> a >> b;
        cout << lca(a, b) << el;
    }


    
    return 0;
}