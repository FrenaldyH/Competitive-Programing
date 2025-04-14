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
    
    int n, tq, i, j;
    cin >> n >> tq;

    vector<int> v(n + 1);
    ordered_multiset dnq;
    for(i = 1; i <= n; i++) 
        cin >> v[i], dnq.insert(v[i]);

    char op;
    while(tq--) {
        cin >> op >> i >> j;
        if(op == '!') {
            auto it = dnq.lower_bound(v[i]); // cout << *it << el;
            dnq.erase(--it); dnq.insert(j), v[i] = j;
        }
        else cout << dnq.order_of_key(j + 1) - dnq.order_of_key(i) << el;
        // for(auto h : dnq) cout << h << " "; cout << el;
    }
    
    return 0;
}

/*
    10 10
5 2 8 7 1 1 2 6 3 1
? 1 3
? 2 3
? 1 4
! 9 10
? 6 6
! 3 3
? 1 5
! 6 2
? 4 10
? 6 10
*/

