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

int n;
vector adj(S + 1, vector<int> ({}));
vector sub(S + 1, 0LL), sum(S + 1, 0LL);

void dfs1(int node = 1, int parent = 0) {
    sub[node] = 1;
    for(int child : adj[node]) {
        if(child == parent)
            continue;
        dfs1(child, node);
        sub[node] += sub[child];
    }
}

void dfs2(int node = 1, int parent = 0, int depth = 0) {
    sum[1] += depth;
    for(int child : adj[node]) {
        if(child == parent)
            continue;
        dfs2(child, node, depth + 1);
    } 
}

void dfs3(int node = 1, int parent = 0) {
    for(int child : adj[node]) {
        if(child == parent)
            continue;
        sum[child] = sum[node] + n - 2 * sub[child];
        dfs3(child, node);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    int i, a, b;
    cin >> n;

    fp(i, 1, n) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs1();
    dfs2();
    dfs3();
    fp(i, 1, n + 1) 
        cout << sum[i] << ' ';
    cout << el;
    
    return 0;
}