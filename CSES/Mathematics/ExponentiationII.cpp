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

const int modulo = 1e9 + 7;
inline ll multiple(ll a, ll b, int mod) {
    return ((a % mod) * (b % mod)) % mod;
}

ll binary_exponentation(ll base, ll power, int mod) {
    if(!power) return 1LL;
    if(power & 1) return multiple(base, binary_exponentation(base, power - 1, mod), mod);
    else return binary_exponentation(multiple(base, base, mod), power/2, mod);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    ll tc, power1, power2, base;
    
    for(cin >> tc; tc--;) {
        cin >> base >> power1 >> power2;
        cout << binary_exponentation(base, binary_exponentation(power1, power2, modulo - 1), modulo) << el;
    }
    
    return 0;
}