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
const int mod = 1e9 + 7;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    ll n, m, i, j, ans = 0;
    cin >> n >> m, m++;

    vector<vector<ll>> dp(n, vector<ll> (m + 1, 0));
    vector<ll> v(n);

    fp(i, 0, n) cin >> v[i];
    fp(i, 0, n)
    {
        if(i)
        {   
            if(v[i])
            {
                dp[i][v[i]] = (dp[i - 1][v[i]]
                + dp[i - 1][v[i] + 1]
                + dp[i - 1][v[i] - 1]) % mod;
            }
            else 
                fp(j, 1, m)
                {
                    dp[i][j] = (dp[i - 1][j] 
                    + dp[i - 1][j - 1]  
                    + dp[i - 1][j + 1]) % mod;
                }
        }
        else
        {
            if(v[i]) dp[i][v[i]] = 1;
            else fp(j, 1, m) dp[i][j] = 1;
        }
    }
    fp(j, 1, m) ans = (ans + dp[n - 1][j]) % mod;
    cout << ans << el;
    return 0;
}

