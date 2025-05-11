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

int n, q, i, x, y;
vector<vector<int>> par, adj;
void dfs(int node = 1) {
    for(int &child : adj[node]) {
        par[child][0] = node;
        for(i = 1; i <= (int)log2(n); i++) 
            par[child][i] = par[par[child][i - 1]][i - 1];
        dfs(child);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    cin >> n >> q;
    adj.resize(n + 1);
    par.resize(n + 1, vector<int> ((int)log2(n) + 1, 0));
    for(i = 2; i <= n; i++) {
        cin >> x;
        adj[x].push_back(i);
    }
    dfs();

    while(q--) {
        cin >> x >> y;
        for(i = log2(n); i >= 0; i--) 
            if(y & (1 << i))
                x = par[x][i];
        cout << (x ? x : -1) << el;
    }
    
    return 0;
}