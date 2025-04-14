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
const int minf = INT_MIN, pinf = INT_MAX;
vector<int> v(200'001);

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less_equal<int>, __gnu_pbds::rb_tree_tag, 
__gnu_pbds::tree_order_statistics_node_update> ordered_multiset;
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, 
__gnu_pbds::tree_order_statistics_node_update> ordered_set;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    int n, k, i;
    cin >> n >> k;

    ordered_multiset otree;
    for(i = 1; i <= n; i++) {
        cin >> v[i], otree.insert(v[i]);
        if(i >= k) {
            if(i > k) otree.erase(--otree.lower_bound(v[i - k]));
            if(k & 1) cout << *otree.find_by_order(k >> 1) << " ";
            else cout << min(*otree.find_by_order(k >> 1), *otree.find_by_order((k >> 1) - 1)) << " ";
        }
    }
    cout << el;
    /* for(i = 0; i < n; i++) 
        cout << i << " " << *otree.find_by_order(i) << el; */
    return 0;
}

