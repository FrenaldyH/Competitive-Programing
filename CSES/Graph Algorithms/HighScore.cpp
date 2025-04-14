#include <bits/stdc++.h>
using namespace std;

//Shortcut
#define fn(i, r, l) for(i = r - 1; i >= l; i--)
#define fp(i, l, r) for(i = l; i < r; i++)
#define ms(x, y) memset(x, y, sizeof(x))
#define all(x) x.begin(), x.end()
#define sc second
#define fr first
#define el '\n'

using dd = double;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

// Global variabel
const ll S = 2500,
minf = LLONG_MIN, 
pinf = LLONG_MAX;

// Fren -> Not, Equal, AND, OR
// ASCII 0 = 48, A = 65, a = 97

struct edges {
    ll u, v, w;
};

vector<edges> edg;
vector dis(S + 1, minf);
vector adj(2, vector<vector<ll>> (S + 1));
vector vis(2, vector<bool> (S + 1, false));

void dfs(int rev, ll node) {
    if(vis[rev][node]) return;
    vis[rev][node] = true;
    for(ll ch : adj[rev][node])
        dfs(rev, ch);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    ll n, m, v[2], d, i, j;
    cin >> n >> m;

    fp(i, 0, m) {
        cin >> v[0] >> v[1] >> d;
        edg.push_back({v[0], v[1], d});
        fn(j, 2, 0) 
            adj[j][v[!j]].push_back(v[j]);
    }

    fp(i, 0, 2) dfs(i, (i ? 1 : n));
    bool cyc = false; dis[1] = 0;

    fp(i, 0, n) {
        for(edges e : edg) {
            if(dis[e.u] == minf) continue;
            if(dis[e.v] < dis[e.u] + e.w) {
                dis[e.v] = dis[e.u] + e.w;
                
                if(i == n - 1 && vis[0][e.v] && vis[1][e.v]) {
                    cyc = true;
                    break;
                }
            }
        }
    }
    
    cout << (cyc ? -1 : dis[n]) << el; 
    return 0;
}