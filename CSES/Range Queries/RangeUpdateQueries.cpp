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

inline int msb(int x) {
    return (x & (-x));
}

void addq(int idx, int x, vector<ll> &f) {
    while(idx < f.size()) {
        f[idx] += x;
        idx += msb(idx);
    }
}

ll sumq(int idx, vector<ll> &f) {
    ll ans = 0;
    while(idx > 0) {
        ans += f[idx];
        idx -= msb(idx);
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    int n, tq, i, op, l, r, k;
    cin >> n >> tq;

    // Buat diff array
    vector<ll> dif(n + 1);
    fp(i, 1, n + 1) cin >> dif[i];
    fn(i, n + 1, 1) if(i) dif[i] -= dif[i - 1];

    // Ubah diff array ke fenwick tree
    vector<ll> ft (n + 1, 0);
    fp(i, 1, n + 1) {
        addq(i, dif[i], ft);
    }

    // Input Queries
    while(tq--)
    {
        cin >> op;
        if(op & 1) {
            cin >> l >> r >> k;
            addq(l, k, ft);
            if(r < n) 
                addq(r + 1, -k, ft);
        }
        else {
            cin >> k;
            cout << sumq(k, ft) << el;
        }
    }
    return 0;
}

