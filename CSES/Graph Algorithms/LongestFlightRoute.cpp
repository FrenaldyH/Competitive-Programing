#include <bits/stdc++.h>
using namespace std;

//Shortcut
#define fn(i, r, l)     for(i = r - 1; i >= l; i--)
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
const int S = 1e5,
minf = INT_MIN, 
pinf = INT_MAX;

// Fren -> Not, Equal, AND, OR
// ASCII 0 = 48, A = 65, a = 97

// Bantu Visualisasi
// https://www.cs.usfca.edu/~galles/visualization/TopoSortIndegree.html

vector<vector<int>> adj(S + 1);
vector<int> 
    deg(S + 1, 0), 
    par(S + 1, 0);
int n, m, a, b, i;
queue<int> bfs;

void topo() {
    while(!bfs.empty()) {
        b = bfs.front(), bfs.pop();
        for(int h : adj[b]) {
            deg[h]--;
            if(!deg[h]) {
                par[h] = b;
                if(h != 1) 
                    bfs.push(h);
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    cin >> n >> m;

    for(i = 0; i < m; i++) {
        cin >> a >> b, deg[b]++;
        adj[a].push_back(b);
    }

    for(i = 2; i <= n; i++) 
        if(!deg[i]) bfs.push(i);
    topo();

    par[1] = par[n] = 0;
    bfs.push(1);
    topo();

    // Debug 1
    /* for(i = 1; i <= n; i++)     
        cout << par[i] << ' ';
    cout << endl; */

    if(par[n]) {
        stack<int> ans; 
        a = n, ans.push(a);
        while(a != 1) {
            a = par[a];
            ans.push(a);
        }

        cout << ans.size() << el;
        while(!ans.empty()) {
            cout << ans.top() << ' ', ans.pop();
        }
    }
    else cout << "IMPOSSIBLE";
    cout << el;
    return 0;
}