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
const ll S = 1e18;

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
    
    ll sum, t, ans, l, r, m; int n, i;
    cin >> n >> t;

    vector<ll> v(n);
    fp(i, 0, n) cin >> v[i];
    sort(all(v));

    l = 1, r = ans = S + 1;
    while(l <= r) {
        m = (l + r) >> 1LL, sum = 0LL;
        for(i = 0; i < n && sum < t; i++) 
            sum += m / v[i];
        
        if(sum >= t) 
            ans = m, r = m - 1;
        else l = m + 1;
    }
    cout << ans << el;
    return 0;
}

