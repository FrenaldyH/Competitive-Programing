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
const int S = 1e5, M = 1e9 + 7,
minf = INT_MIN, 
pinf = INT_MAX;

// Fren -> Not, Equal, AND, OR
// ASCII 0 = 48, A = 65, a = 97

vector<vector<int>> 
    adj1(S + 1);
vector<int> 
    deg(S + 1, 0),
    pos(S + 1, 0);
queue<int> bfs;
int n, m, a, b, i;

void topo() {
    while(!bfs.empty()) {
        b = bfs.front(), bfs.pop();
        for(auto &h : adj1[b]) {
            deg[h]--;
            pos[h] = (pos[h] + pos[b]) % M;
            if(!deg[h] && h != 1) 
                bfs.push(h);
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    cin >> n >> m;
    fp(i, 0, m) {
        cin >> a >> b, deg[b]++;
        adj1[a].push_back(b);
    }

    fp(i, 2, n + 1) 
        if(!deg[i]) 
             bfs.push(i);
    topo();

    bfs.push(1), 
    pos[1] = 1;
    topo();

    cout << pos[n] << el;


    return 0;
}