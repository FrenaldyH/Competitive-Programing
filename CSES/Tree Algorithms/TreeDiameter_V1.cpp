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
const int M = 200'001;

/* #include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less_equal<int>, __gnu_pbds::rb_tree_tag, 
__gnu_pbds::tree_order_statistics_node_update> ordered_multiset;
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, 
__gnu_pbds::tree_order_statistics_node_update> ordered_set; */
vector<vector<int>> tree(M);
vector<int> dist(M);

void dfs(int node, int parent) {
    for(int child : tree[node]) {
        if(child ^ parent) {
            dist[child] = dist[node] + 1;
            dfs(child, node);
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    int n, i, a, b, maxdist, node;
    cin >> n;
    fp(i, 1, n) {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dist[1] = 0;
    dfs(1, 0);

    // Find end-point 
    maxdist = 0, node = 1;
    fp(i, 1, n + 1) {
        if(dist[i] > maxdist) 
            maxdist = dist[i], node = i;
        dist[i] = 0;
    }
    
    dfs(node, 0);
    maxdist = 0;
    fp(i, 1, n + 1) 
        maxdist = max(maxdist, dist[i]);
    cout << maxdist << el;

    return 0;
}

