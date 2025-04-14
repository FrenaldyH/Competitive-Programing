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
minf = -1e12, 
pinf =  1e12;

// Fren -> Not, Equal, AND, OR
// ASCII 0 = 48, A = 65, a = 97

vector bes(S + 1, priority_queue<ll> ());
vector adj(S + 1, vector<pll> ({}));
vector<ll> dis(S + 1, pinf);

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    ll n, m, k, i, a, b, c, t;
    cin >> n >> m >> k;

    for(i = 0; i < m; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    priority_queue<pll, vector<pll>, greater<pll>> pq; 
    pq.push({0, 1}), dis[1] = 0, bes[1].push(0);
    while(!pq.empty()) {
        tie(a, b) = pq.top(), pq.pop();
        if(a > bes[b].top()) continue;
        for(pll p : adj[b]) {
            t = p.sc + a;
            if(bes[p.fr].size() < k) {
                bes[p.fr].push(t);
                pq.push({t, p.fr});
            }
            else if(bes[p.fr].top() > t) {
                bes[p.fr].pop();
                bes[p.fr].push(t);
                pq.push({t, p.fr});
            }
        }
    }

    stack<ll> ans;
    while(!bes[n].empty()) {
        ans.push(bes[n].top()), bes[n].pop();
    }
    while(!ans.empty()) {
        cout << ans.top() << ' ', ans.pop();
    }
    cout << el;
    return 0;
}