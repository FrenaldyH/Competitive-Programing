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
const int S = 2e5,
minf = INT_MIN, 
pinf = INT_MAX;

// Fren -> Not, Equal, AND, OR
// ASCII 0 = 48, A = 65, a = 97

vector<int> 
    tl(S + 1, 0), // to leaf
    ml(S + 1, 0); // max length
vector adj(S + 1, vector<int> ());

int ans = 0;
void dptree(int node = 1, int par = 0) {
    int a = 0, b = 0;
    for(int h : adj[node]) {
        if(h == par) continue;
        dptree(h, node);
        
        if(a < tl[h] + 1) {
            b = a, a = tl[h] + 1;
        }else 
        if(b < tl[h] + 1) {
            b = tl[h] + 1;
        }
        // cout << node << ' ' << h << ' ' << a << ' ' << b << ' ' << tl[h] + 1 << el;
    }
    // cout << node << ' ' << a << ' ' << b << el;
    tl[node] = a;
    ml[node] = a + b;
    ans = max(ans, ml[node]);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    int n, a, b, i;
    cin >> n;
    fp(i, 1, n) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dptree();
    cout << ans << el;
    /*  fp(i, 1, n + 1) 
        cout << tl[i] << ' ' << ml[i] << el;  */

    return 0;
}
