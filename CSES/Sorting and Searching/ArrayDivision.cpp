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
    
    ll n, i, max_seg, max_num, t_sum, max_sum, seg, ans, sum, tm_sum;
    cin >> n >> max_seg;
    vector<ll> fk(n + 1);

    max_num = t_sum = 0;
    for(i = 1; i <= n; i++) {
        cin >> fk[i], t_sum += fk[i];
        max_num = max(max_num, fk[i]);
    }

    ans = LLONG_MAX;
    while(max_num <= t_sum) {
        max_sum = (max_num + t_sum) >> 1;

        // cout << "max_sum : " << max_sum << el;
        sum = tm_sum = seg = 0LL;
        for(i = 1; i <= n; i++) {
            sum += fk[i];
            if(sum > max_sum) {
                tm_sum = max(tm_sum, sum - fk[i]);
                seg++, i--, sum = 0;
            }
        }
        if(sum > 0) tm_sum = max(tm_sum, sum), seg++;

        if(seg <= max_seg) {
            t_sum = max_sum - 1;
            ans = min(ans, tm_sum);
        }
        else max_num = max_sum + 1;
    }
    cout << ans << el;
    
    return 0;
}

