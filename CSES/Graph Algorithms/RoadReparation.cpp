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

vector<int> 
    par(S + 1),
    siz(S + 1);

int fin(int &y) {
    return (y == par[y] ? y : y = fin(par[y]));
}

void unite(int x, int y) {
    x = fin(x);
    y = fin(y);
    if(siz[x] < siz[y])
    swap(x, y);
    siz[x] += siz[y];
    par[y] =  par[x];
}

bool comp(vector<int> &x, vector<int> &y) {
    return x[2] < y[2];
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    int n, m, i, j;
    cin >> n >> m;

    vector<vector<int>> edge(
        (m), vector<int> (3)
    );

    fp(i, 0, m) 
        fp(j, 0, 3) 
            cin >> edge[i][j];
    sort(all(edge), comp);

    // Debug 1
    /* fp(i, 0, m) {
        fp(j, 0, 3) 
            cout << edge[i][j] << ' ';
        cout << el;
    } */

    fp(i, 1, n + 1) 
        par[i] = i, 
        siz[i] = 1;

    ll ans = 0;
    fp(i, 0, m) {
        if(fin(edge[i][0]) != fin(edge[i][1])) {
            unite(edge[i][0], edge[i][1]);
            ans += edge[i][2];
        }
    }   
    
    m = 1, m = fin(m); 
    if(siz[m] == n) 
        cout << ans;
    else cout << "IMPOSSIBLE";
    cout << el; 

    return 0;
}