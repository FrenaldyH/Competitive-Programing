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

/* #include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less_equal<int>, __gnu_pbds::rb_tree_tag, 
__gnu_pbds::tree_order_statistics_node_update> ordered_multiset;
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, 
__gnu_pbds::tree_order_statistics_node_update> ordered_set; */

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    int  n, i, j, k;
    cin >> n;
    
    vector<ll> fk(n + 1);
    vector<vector<ll>> dp(n + 1, vector<ll> (n + 1)); 

    fp(i, 1, n + 1) 
        cin >> dp[i][i], fk[i] = fk[i - 1] + dp[i][i];

    for(k = 1; k < n; k++) 
        for(i = 1, j = 1 + k; j <= n; i++, j++) 
            dp[i][j] = max(dp[i][i] + fk[j] - fk[i] - dp[i + 1][j], 
                            dp[j][j] + fk[j - 1] - fk[i - 1] - dp[i][j - 1]);
    cout << dp[1][n] << el;
}

/* 
    vector<vector<vector<ll>>> dp(2, vector<vector<ll>> (n + 1, vector<ll> (n + 1)));

    fp(i, 1, n + 1) cin >> dp[1][i][i];

    ll a, b;
    for(k = 1; k < n; k++) {
        for(i = 1, j = k + 1; j <= n; i++, j++) {
            a = dp[1][i][i] + dp[0][i + 1][j];
            b = dp[1][j][j] + dp[0][i][j - 1];

            if(a >= b)
                dp[1][i][j] = a, dp[0][i][j] = dp[1][i + 1][j];
            else 
                dp[1][i][j] = b, dp[0][i][j] = dp[1][i][j - 1];
        }
    }
    cout << dp[1][1][n] << el;
    return 0; */
