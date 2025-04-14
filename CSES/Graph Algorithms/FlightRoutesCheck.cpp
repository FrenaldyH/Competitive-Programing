#include <bits/stdc++.h>
using namespace std;

//Shortcut
#define fn(i, r, l)     for(i = r - 1; i >= l; i--)
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

vector<vector<vector<int>>> adj (
    2, vector<vector<int>> (
        S + 1, vector<int> ()
    )
);
vector<vector<bool>> can (
    2, vector<bool> (
        S + 1, false
    )
);

void dfs(int node, int op) {
    can[op][node] = 1;
    for(int child : adj[op][node]) {
        if(!can[op][child]) {
            dfs(child, op);
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    int n, m, a, b, i;
    cin >> n >> m;

    fp(i, 0, m) {
        cin >> a >> b;
        adj[0][a].push_back(b);
        adj[1][b].push_back(a);
    }

    fp(i, 0, 2) {
        dfs(1, i);
    }

    for(i = 2; i <= n; i++) {
        if(!can[0][i]) {
            cout << "NO\n" << 1 << ' ' << i << el;
            return 0;
        }
        if(!can[1][i]) {
            cout << "NO\n" << i << ' ' << 1 << el;
            return 0;
        }   
    }
    cout << "YES" << el;
    return 0;
}