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
const ll S = 1e5,
minf = LLONG_MIN, 
pinf = LLONG_MAX,
mod = 1e9 + 7;

// priority_queue <data_type, vector<data_type>, greater<data_type>> variable_name; 
// Fren -> Not, Equal, AND, OR
// ASCII 0 = 48, A = 65, a = 97

struct city{
    ll 
        min_price,
        min_count,
        max_flight,
        min_flight;
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);

    int n, m, i, a, b, c;
    cin >> n >> m;
    
    vector<city> node(n + 1);
    vector<vector<pll>> adj(n + 1);

    for(i = 1; i <= n; i++) {
        node[i].max_flight = minf;
        node[i].min_flight = pinf;
        node[i].min_price = pinf;
        node[i].min_count = 0;
    }

    while(m--) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    node[1].max_flight = 0;
    node[1].min_flight = 0;
    node[1].min_count = 1;
    node[1].min_price = 0;

    priority_queue<pll, vector<pll>, greater<pll>> bfs;
    bfs.push({0, 1});
    while(!bfs.empty()) {
        pll t = bfs.top(); bfs.pop();
        for(pll p : adj[t.sc]) {
            if(node[p.fr].min_price > t.fr + p.sc) {
                node[p.fr] = node[t.sc];
                node[p.fr].min_flight++;
                node[p.fr].max_flight++;
                node[p.fr].min_price += p.sc;
                bfs.push({node[p.fr].min_price, p.fr});
            }
            else if(node[p.fr].min_price == t.fr + p.sc) {
                node[p.fr].min_count = (node[p.fr].min_count + node[t.sc].min_count) % mod;
                node[p.fr].max_flight = max(node[p.fr].max_flight, node[t.sc].max_flight + 1);
                node[p.fr].min_flight = min(node[p.fr].min_flight, node[t.sc].min_flight + 1);
            }
        }
    }
    cout << node[n].min_price << ' '
         << node[n].min_count << ' '
         << node[n].min_flight << ' '
         << node[n].max_flight << el;

    return 0;
}