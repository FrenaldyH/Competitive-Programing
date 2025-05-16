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

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    int n, i, prev;
    cin >> n;
    vector<int> v(n + 1), dp(n + 1);
    for(i = 1; i <= n; i++) 
        cin >> v[i];
    sort(all(v));

    for(i = 1; i <= n; i++) {
        if(v[i] == v[i - 1]) {
            dp[i] = (dp[i - 1] + prev) % mod;
        }
        else {
            prev = dp[i - 1];
            dp[i] = (dp[i - 1] * 2) % mod;
        }
        dp[i] = (dp[i] + 1) % mod;
    }
    cout << dp[n] << el;
    return 0;
}

