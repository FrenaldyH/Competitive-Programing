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

/**
 * Problem: https://codeforces.com/gym/102694/problem/C
 * Solved : 10.05.2025
**/

vector<vector<int>> adj, par;
vector<int> depth;
int n, i, j;

void dfs(int node, int parent = 0) {
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
    
    for(i = (int)log2(n); i >= 0; i--) {
        if((depth[node1] - depth[node2]) & (1 << i)) 
            node1 = par[node1][i];
    }
    if(node1 == node2) return node1;

    for(i = (int)log2(n); i >= 0; i--) {
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
    
    int q, a, b, c, d, dis1, dis2;
    cin >> n;

    par.resize(n + 1, vector<int> ((int)log2(n) + 1, 1));
    depth.resize(n + 1);
    adj.resize(n + 1);
    
    for(i = 1; i < n; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    depth[1] = 0;
    dfs(1);

    for(cin >> q; q--;) {
        cin >> a >> b >> d;
        c = lca(a, b);
        dis1 = depth[a] - depth[c];
        dis2 = depth[b] - depth[c];

        if(dis1 > d) {
            for(i = (int)log2(n); i >= 0; i--) 
                if(d & (1 << i))
                    a = par[a][i];
            cout << a << el;
        }
        else if(dis1 + dis2 > d) {
            dis2 -= (d - dis1);
            for(i = (int)log2(n); i >= 0; i--) 
                if(dis2 & (1 << i))
                    b = par[b][i];
            cout << b << el;
        }
        else cout << b << el;
    }

    return 0;
}

/*
6
1 2
2 3
3 4
1 5
5 6
6
4 6 1
4 6 2
4 6 3
4 6 4
4 6 5 
4 6 6
*/