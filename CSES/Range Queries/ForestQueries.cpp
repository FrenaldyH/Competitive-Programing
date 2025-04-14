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
    
    ll a, b, c, d, n, tq;
    char h;

    cin >> n >> tq;
    vector<vector<ll>> dp(n + 1, vector<ll> (n + 1, 0));
   
    fp(a, 1, n + 1)
    {
        fp(b, 1, n + 1)
        {
            cin >> h;
            if(h == '*')
                dp[a][b] = 1;
        }
    }
    
    fp(a, 1, n + 1)
        fp(b, 1, n + 1)
            dp[a][b] += (dp[a - 1][b] + dp[a][b - 1] - dp[a - 1][b - 1]);

    /* fp(a, 1, n + 1)
    {
        fp(b, 1, n + 1)
            cout << dp[a][b] << " ";
        cout << el;
    } */
        
    while(tq--)
    {
        cin >> a >> b >> c >> d;
        cout << (dp[c][d] - dp[c][b - 1] - dp[a - 1][d] + dp[a- 1][b - 1]) << el;
    }
    return 0;
}

