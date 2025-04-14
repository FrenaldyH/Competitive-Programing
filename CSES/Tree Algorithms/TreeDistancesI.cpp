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

// Global variabel
const int S = 2e5,
minf = INT_MIN, 
pinf = INT_MAX;

// Fren -> Not, Equal, AND, OR
// ASCII 0 = 48, A = 65, a = 97

vector adj(S + 1, vector<int> ({}));

void dfs(vector<int> &dis, int node, int parent = 0) {
    for(int &child : adj[node]) {
        if(child != parent) {
            dis[child] = dis[node] + 1;
            dfs(dis, child, node);
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    int n, i, a, b, t;
    cin >> n;
    vector<int> 
    dis1(S + 1, 0), 
    dis2(S + 1, 0);

    fp(i, 1, n) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dis1[1] = a = b = 0; dfs(dis1, 1);
    for(i = 1; i <= n; i++) 
        if(b < dis1[i])
            b = dis1[i], a = i;

    /* for(i = 1; i <= n; i++)
        cout << dis1[i] << ' ';
    cout << el; */

    dis1[a] = t = b = 0; dfs(dis1, a);
    for(i = 1; i <= n; i++)
        if(t < dis1[i])
            t = dis1[i], b = i;

    dis2[b] = 0; dfs(dis2, b);
    for(i = 1; i <= n; i++)
        cout << max(dis1[i], dis2[i]) << ' ';
    cout << el;
    
    return 0;
}