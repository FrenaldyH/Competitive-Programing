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
const ll S = 500,
minf = LLONG_MIN, 
pinf = LLONG_MAX;

// Fren -> Not, Equal, AND, OR
// ASCII 0 = 48, A = 65, a = 97

vector mat(S + 1, vector<ll> (S + 1, pinf));


int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    ll tq, n, m, a, b, w, i, j, k;
    cin >> n >> m >> tq;

    fp(i, 0, m) {
        cin >> a >> b >> w;
        mat[a][b] = min(mat[a][b], w),
        mat[b][a] = min(mat[b][a], w);
    }
    for(i = 1; i <= n; i++)
        mat[i][i] = 0;

    for(k = 1; k <= n; k++) {
        for(i = 1; i <= n; i++) {
            for(j = 1; j < i; j++) {
                if(mat[i][k] == pinf || mat[k][j] == pinf)
                    continue;
                mat[i][j] = mat[j][i] = min(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }
    }

    /* for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++)
            cout << (mat[i][j] == pinf ? -1 : mat[i][j]) << ' ';
        cout << el;
    } */

    while(tq--) {
        cin >> i >> j;
        cout << (mat[i][j] == pinf ? -1 : mat[i][j]) << el;
    }
    
    return 0;
}