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

void updtq(vector<int> &tree, int idx, int val) {
    tree[idx] = val;
    for(idx >>= 1; idx > 0; idx >>= 1) {
        tree[idx] = min(tree[idx * 2], tree[idx * 2 + 1]);
    }
}

int dsplyq(const vector<int>& tree, int n, int l, int r) {
    l += n; 
    r += n; 
    int ans = INT_MAX; 
    while (l <= r) {
        if (l % 2 == 1) {
            ans = min(ans, tree[l]);
            l++;
        }
        if (r % 2 == 0) {
            ans = min(ans, tree[r]);
            r--;
        }
        l >>= 1;
        r >>= 1;
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    int n, tq, i, a, b;
    cin >> n >> tq;

    vector<int> tree(n * 2);
    for(i = 0; i < n; i++)
        cin >> tree[i + n];

    // Built Segment Tree
    for(i = n - 1; i > 0; i--)
        tree[i] = min(tree[i * 2], tree[i * 2 + 1]);

    // Testing update
    /* for(i = 0; i < tq; i++)
    {
        cin >> a >> b;
        update(tree, a + n - 1, b);
        for(int h : tree)
            cout << h << " ";
        cout << el; 
    } */

    while(tq--)
    {
        cin >> i >> a >> b;
        if(i & 1)
            updtq(tree, a + n - 1, b);
        else 
            cout << dsplyq(tree, n, a - 1, b - 1) << el;
    }
    return 0;
}

