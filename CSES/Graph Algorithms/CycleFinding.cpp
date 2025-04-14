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
const ll S = 2500,
minf = -1e12, 
pinf =  1e12;

// Fren -> Not, Equal, AND, OR
// ASCII 0 = 48, A = 65, a = 97

vector<vector<ll>> edge(S*2 + 1, vector<ll> (3));
vector<ll> par(S + 1), dis(S + 1);
int n, m, a, b, c, i, j;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    cin >> n >> m;
    for(i = 0; i < m; i++) {
        cin >> a >> b >> c;
        edge[i] = {a, b, c};
    }

    /* for(i = 0; i < m; i++)
        cout << edge[i][0] << ' ' << edge[i][1] << ' ' << edge[i][2] << el; */

    for(i = 1; i <= S; i++) 
        dis[i] = pinf;
    dis[1] = 0;

    // Bellman ford
    for(i = 1; i < n; i++) {
        for(j = 0; j < m; j++) {
            if(dis[edge[j][1]] > dis[edge[j][0]] + edge[j][2]) {
                dis[edge[j][1]] = dis[edge[j][0]] + edge[j][2];
                par[edge[j][1]] = edge[j][0];
                // cout << edge[j][1] << ' ';
            }
        }
        // cout << el;
    }

    // Cek Negative Cycle
    bool cyc = false;
    for(j = i = 0; j < m; j++) {
        if(dis[edge[j][1]] > dis[edge[j][0]] + edge[j][2]) {
            dis[edge[j][1]] = dis[edge[j][0]] + edge[j][2];
            par[edge[j][1]] = edge[j][0];
            cyc |= true, i = edge[j][1];
        }
    }

    /* for(j = 1; j <= n; j++)
        cout << j << ' ' << par[j] << el; */

    if(cyc) {
        cout << "YES\n";
        for(j = 1; j <= n; j++) 
            i = par[i]; 

        stack<int> rev; rev.push(i);
        for(j = par[i];; j = par[j]) {
            rev.push(j), cyc &= false;
            if(j == i && !cyc) break;
        }

        while(!rev.empty()) {
            cout << rev.top() << ' ', rev.pop();
        }
    }
    else cout << "NO\n";

    return 0;
}