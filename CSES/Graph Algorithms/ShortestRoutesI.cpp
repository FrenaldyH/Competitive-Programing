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
minf = LLONG_MIN, 
pinf = LLONG_MAX;


// Fren -> Not, Equal, AND, OR
// ASCII 0 = 48, A = 65, a = 97

vector graph (S + 1, vector<pll> ({}));
vector dist (S + 1, pinf);
vector vis (S + 1, false);

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    ll n, m, i, a, b, d, t;
    cin >> n >> m; 

    fp(i, 0, m) {
        cin >> a >> b >> d;
        graph[a].push_back({b, d});
    }

    priority_queue<pll, vector<pll>, greater<pll>> bfs;
    bfs.push({0, 1}), dist[1] = 0;
    while(!bfs.empty()) {
        t = bfs.top().sc, bfs.pop();
        if(vis[t]) continue;

        vis[t] = true;
        for(pll ch : graph[t]) {
            if(dist[ch.fr] > ch.sc + dist[t]) {
                dist[ch.fr] = ch.sc + dist[t];
                bfs.push({dist[ch.fr], ch.fr});
            }
        }
    }

    fp(i, 1, n + 1)
        cout << dist[i] << ' ';
    cout << el;
    return 0;
}