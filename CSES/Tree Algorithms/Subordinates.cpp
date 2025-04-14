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
const int m = 200'001;
vector<int> dp(m);
vector<vector<int>> tree(m);

/* #include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less_equal<int>, __gnu_pbds::rb_tree_tag, 
__gnu_pbds::tree_order_statistics_node_update> ordered_multiset;
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, 
__gnu_pbds::tree_order_statistics_node_update> ordered_set; */

int dfs(int node) {
    if(tree[node].empty())
        return 1;
    for(auto i : tree[node]) {
        dp[node] += dfs(i);
    }
    return dp[node] + 1;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    int n, i, x;
    cin >> n;

    fp(i, 1, n) {
        cin >> x, x--;
        tree[x].push_back(i);
    }

    // Proccess
    dfs(0);
    fp(i, 0, n) {
        cout << dp[i] << " ";
    } cout << el;
    
    return 0;
}

