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
const ll mod = 1e9 + 7;
const int S  = 1e6 - 1;

// Tutorial Link : https://www.youtube.com/watch?v=MxhA0bY31wM
/*
    in this code i'am useing this implement : top active, top pasive, bottom active, bottom pasive
*/

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    vector<bool> 
    bot {1, 1, 1, 0, 1, 1, 0, 0},
    top {1, 0, 1, 1, 1, 1, 0, 0};
    vector<vector<ll>> dp(S, vector<ll> (8, 0));
    
    int tc, n, i, b, t; ll ans;
    for(i = 0; i < 8; i++)  // Initialize n = 2
        dp[0][i] = 1;
    
    for(i = 1; i < S; i++)  // From dp 3 until S (1'000'000)
        for(b = 0; b < 8; b++) 
            for(t = 0; t < 8; t++) 
                dp[i][b] = (dp[i][b] + dp[i - 1][t] * (ll)(bot[b] == top[t])) % mod;
            
    // Debug 1
    /* for(i = 0; i < 5; i++) {
        ans = 0;
        for(b = 0; b < 8; b++)
            ans = (ans + dp[i][b]) % mod;
        cout << ans << el;
    } */

    cin >> tc;
    while(tc--) {
        cin >> n;
        if(n <= 2) {
            cout << ((n & 1) ? 2 : 8) << el;
            continue;
        }

        ans = 0;
        for(i = 0; i < 8; i++) 
            ans = (ans + dp[n - 2][i]) % mod;
        cout << ans << el;
    }
    return 0;
}

