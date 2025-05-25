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
pinf = INT_MAX,
mod = 1e9 + 7;

// Fren -> Not, Equal, AND, OR
// ASCII 0 = 48, A = 65, a = 97

struct {
    int un;
    vector<int> parent; 
    vector<ll> size, price;

    void init(int input_size) {
        un = input_size;
        price.resize(un + 1);
        parent.resize(un + 1);
        size.resize(un + 1, 1);
        for(int i = 1; i <= un; i++) 
            parent[i] = i;
    }
    int find(int root) {
        if(root == parent[root]) 
            return root;
        return parent[root] = find(parent[root]);
    }
    bool unite(int ra, int rb) {
        ra = find(ra);
        rb = find(rb);  
        if(ra == rb) return false;

        if(price[ra] > price[rb] || (price[ra] == price[rb] && size[ra] < size[rb])) 
            swap(ra, rb);

        size[ra] += size[rb];
        parent[rb] = ra;
        un--;
        return true;
    }
} dsu;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    int n, m, x, i, a, b;
    cin >> n >> m >> x;
    dsu.init(n);

    for(i = 1; i <= n; i++) 
        cin >> dsu.price[i];
    for(i = 1; i <= m; i++) {
        cin >> a >> b;
        dsu.unite(a, b);
    }

    ll ans = 0, minkol = pinf;
    vector<pll> kol;
    vector<bool> vis(n + 1);
    for(i = 1; i <= n; i++) {
        a = dsu.find(i);
        if(!vis[a]) {
            kol.push_back({dsu.price[a] * dsu.size[a], a});
            vis[a] = true;
            if(minkol > dsu.price[a])
                minkol = dsu.price[a];
        }
    }

    sort(all(kol), greater());
    for(i = 0; i < dsu.un && x; i++) {
        if(minkol < dsu.price[kol[i].sc]) {
            kol[i].fr = minkol * dsu.size[kol[i].sc];
            x--;
        }
    }

    for(i = 0; i < dsu.un; i++) 
        ans += kol[i].fr;
    cout << ans << el;

    return 0;
}
