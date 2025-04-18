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

ll solve(ll x) {
    return (x / 3 + ((x % 3) ? 1 : 0));
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if(!b && !c)
        a += d, d = 0;
    else if(!b)
        a += c, c = 0;
    else if(!c)
        b += d, d = 0;
    else
        b += c, c = 0;
    cout << solve(a) + solve(b) + solve(d) << el;
    return 0;
}
