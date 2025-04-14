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


int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    int n, k, i, ans;
    cin >> n >> k;

    vector<pii> v(n);
    fp(i, 0, n) {
        cin >> v[i].sc >> v[i].fr; 
    }
    sort(all(v));
    
    /* cout << el;
    for(auto p : v) 
        cout << p.fr << ' ' << p.sc << el; */

    multiset<int> end;
    fp(i, 0, k) end.insert(0);
    for(i = ans = 0; i < n; i++) {
        auto it = end.upper_bound(v[i].sc);
        if(it == begin(end)) continue;

        end.erase(--it), ans++;
        end.insert(v[i].fr);
    }
    cout << ans << el;
    return 0;
}