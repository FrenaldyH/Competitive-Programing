#include <bits/stdc++.h>
using namespace std;

//Shortcut
#define fp(i, l, r)     for(i = l; i < r; i++)
#define ms(x, y)        memset(x, y, sizeof(x))
#define all(x)          x.begin(), x.end()
#define sc              second
#define fr              first
#define el              '\n'

using dd                = double;
using ll                = long long;
using ull               = unsigned long long;
using pii               = pair<int, int>;
using pll               = pair<ll, ll>;

// Global variabel
const int S = 3e5,
minf = INT_MIN, 
pinf = INT_MAX;

// Fren -> Not, Equal, AND, OR
// ASCII 0 = 48, A = 65, a = 97

/**
 * Problem: https://codeforces.com/gym/102694/problem/B
 * Solved : 10.05.2025
**/

vector<vector<int>> adj(S + 1);
void dfs(vector<int> &dis, int node, int parent = 0) {
    for(int &child : adj[node]) {
        if(child != parent) {
            dis[child] = dis[node] + 1;
            dfs(dis, child, node);
        }
    }
}

int n, a, b, i, st, nd, max_dist;
int rawr(vector<int> &dis) {
    int node;
    for(i = 1; i <= n; i++) 
        if(max_dist < dis[i])
            max_dist = dis[node = i];
    return node;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    cin >> n;
    for(i = 1; i < n; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> dis1(n + 1), dis2(n + 1), dis3(n + 1);

    dis1[1] = 0; 
    dfs(dis1, 1);

    max_dist = 0;
    st = rawr(dis1);
    dis1[st] = 0;
    dfs(dis1, st);

    max_dist = 0;
    nd = rawr(dis1);
    dis2[nd] = 0;
    dfs(dis2, nd);

    for(i = 1; i <= n; i++) {
        cout << max(max_dist, max(dis1[i], dis2[i]) + 1) << el;
    }

    return 0;
}
