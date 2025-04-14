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

vector<bool> cek (S + 1);
vector<int> h (S + 1), v (S + 1);

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    int n, m, i, a, b, c, t;
    cin >> n >> m;

    fp(i, 1, n + 1) 
        cin >> v[i],
        h[v[i]] = i;

    c = 1;
    fp(i, 1, n + 1) {
        if(h[i] > h[i - 1])
            cek[i] = true;
        else c++;
    }
    
    while(m--) {
        cin >> a >> b, t = 0;
        swap(h[v[a]], h[v[b]]);
        swap(v[a],       v[b]);

        if(cek[v[a]] && h[v[a]] < h[v[a] - 1])
            t++, cek[v[a]] = 0;
        if(cek[v[b]] && h[v[b]] < h[v[b] - 1])
            t++, cek[v[b]] = 0;
        if(!cek[v[a]] && h[v[a]] > h[v[a] - 1])
            t--, cek[v[a]] = 1;
        if(!cek[v[b]] && h[v[b]] > h[v[b] - 1])
            t--, cek[v[b]] = 1;

        if(cek[v[a] + 1] && h[v[a] + 1] < h[v[a]])
            t++, cek[v[a] + 1] = 0;
        if(cek[v[b] + 1] && h[v[b] + 1] < h[v[b]])
            t++, cek[v[b] + 1] = 0;
        if(!cek[v[a] + 1] && h[v[a] + 1] > h[v[a]])
            t--, cek[v[a] + 1] = 1;
        if(!cek[v[b] + 1] && h[v[b] + 1] > h[v[b]])
            t--, cek[v[b] + 1] = 1;

        c += t, cout << c << el;
    }
    

    return 0;
}