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
const int S = 1e5,
minf = INT_MIN, 
pinf = INT_MAX;

// Fren -> Not, Equal, AND, OR
// ASCII 0 = 48, A = 65, a = 97
vector<bool> vis(S + 1, 1);
vector<unordered_set<int>> 
    adj1(S + 1),
    adj2(S + 1);

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    int n, m, c, a, b, i;
    cin >> n >> m;

    for(i = 0; i < m; i++) {
        cin >> a >> b, vis[b] = 0;
        adj1[a].insert(b);
        adj2[b].insert(a);
    }

    queue<int> bfs, ans; 
    for(i = 1; i <= n; i++) 
        if(vis[i]) bfs.push(i);

    c = 0;
    while(!bfs.empty()) {
        b = bfs.front(), bfs.pop();
        vis[b] = true, ans.push(b), c++;
        for(auto h : adj1[b]) {
            adj2[h].erase(b);
            if(adj2[h].empty())
                bfs.push(h);
        }
    }

    if(c == n) {
        while(!ans.empty()) {
            cout << ans.front() << ' ', ans.pop();
        }
    }
    else cout << "IMPOSSIBLE";
    cout << el;
    
    return 0;
}