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
const int M = 200'001, minf = INT_MIN;

/* #include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less_equal<int>, __gnu_pbds::rb_tree_tag, 
__gnu_pbds::tree_order_statistics_node_update> ordered_multiset;
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, 
__gnu_pbds::tree_order_statistics_node_update> ordered_set; */

vector<vector<int>> dp(2, vector<int> (M)), tree(M);
void dfs(int node, int parent) {
    dp[0][node] = 0, dp[1][node] = minf;

    for(int child : tree[node]) {
        if(child == parent) continue;

        dfs(child, node);
        dp[0][node] += max(dp[0][child], dp[1][child]);
        dp[1][node] = max(dp[1][node], 
                        min(dp[0][child] - dp[1][child], 0));
    }
    dp[1][node] += dp[0][node] + 1;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    int n, i, j;
    cin >> n;

    while(--n) {
        cin >> i >> j;
        tree[i].push_back(j);
        tree[j].push_back(i);
    }
    dfs(1, 0); cout << max(dp[1][1], 0) << el;
    return 0;
}

