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

vector<int> vis(S + 1, 0);
vector adj(S + 1, vector<int> ());
stack<int> pat, ans;

bool found = 0, cycle = 0;
void dfs(int node) {
    vis[node] = 1;
    for(int child : adj[node]) {
        pat.push(node);

        if(vis[child] == 1) {
            pat.push(child);
            found = 1;
            return;
        }
        else if(!vis[child]) dfs(child);
        if(found) return;

        pat.pop();
    }
    vis[node] = 2;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    int n, m, a, b, i;
    cin >> n >> m;

    for(i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for(i = 1; i <= n; i++) {
        if(vis[i]) continue;
        else dfs(i);

        if(found) {
            while(!pat.empty()) {
                ans.push(pat.top());
                if(!vis[pat.top()]) break;
                vis[pat.top()] = 0, pat.pop();
            }
            cout << ans.size() << el;
            while(!ans.empty()) {
                cout << ans.top() << ' ', ans.pop();
            }
            cout << el;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << el;
    return 0;
}

/*
    Testcase
    4 4
    1 2
    2 3
    3 4
    4 2
*/