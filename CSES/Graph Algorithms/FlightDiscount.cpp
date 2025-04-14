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
const ll S = 1e5,
minf = LLONG_MAX, 
pinf = LLONG_MAX;

// Fren -> Not, Equal, AND, OR
// ASCII 0 = 48, A = 65, a = 97

int n, m, a, b, i; ll c, d;
vector<vector<ll>> dist(2, vector<ll> (S + 1, pinf));
vector<vector<vector<pair<int, ll>>>> adj(2, 
        vector<vector<pair<int, ll>>> (S + 1, 
                vector<pair<int,ll>> ({})));

void djk(int node, int op) {
    b = (op ? n : 1);

    priority_queue<pair<ll, int>> pq;
    dist[op][node] = 0, pq.push({0, b});

    while(!pq.empty()) {
        tie(c, a) = pq.top(), pq.pop();

        // Has been visit before
        if(-c != dist[op][a])
            continue;
        for(auto [p, q] : adj[op][a]) {
            ll td = dist[op][a] + q;
            if(td < dist[op][p]) {
                dist[op][p] = td;
                pq.push({-td, p});
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    cin >> n >> m;
    fp(i, 0, m) {
        cin >> a >> b >> c;
        adj[0][a].push_back({b, c});
        adj[1][b].push_back({a, c});
    }

    djk(1, 0);
    djk(n, 1);

    //Debug
    /* for(i = 1; i <= n; i++)
        cout << dist[0][i] << ' ';
    cout << el;
    for(i = 1; i <= n; i++)
        cout << dist[1][i] << ' ';
    cout << el; */

    ll ans = pinf;
    fp(i, 1, n + 1) {
        for(auto [p, q] : adj[0][i]) {
            if(dist[0][i] == pinf || 
                dist[1][p] == pinf)
                    continue;
            ans = min(ans, dist[0][i] + (q >> 1LL) + dist[1][p]);
        }
    }
    cout << ans << el;
    return 0;
}