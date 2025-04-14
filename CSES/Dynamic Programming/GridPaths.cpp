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
const int mod = 1e9 + 7;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    int n, i, j;
    cin >> n;

    vector<vector<char>> m(n, vector<char> (n));
    vector<vector<ll>> v(n, vector<ll> (n, 0));
    fp(i, 0, n) fp(j, 0, n) cin >> m[i][j];

    // Base case
    fp(i, 0, n)
    {
        if(m[i][0] == '.')
            v[i][0] = 1;
        else break;
    }
    fp(j, 0, n)
    {
        if(m[0][j] == '.')
            v[0][j] = 1;
        else break;
    }
    
    fp(i, 1, n)
        fp(j, 1, n)
            if(m[i][j] == '.')
                v[i][j] = (v[i - 1][j] + v[i][j - 1]) % mod;
    cout << v[n - 1][n - 1] << el;
    
    return 0;
}

