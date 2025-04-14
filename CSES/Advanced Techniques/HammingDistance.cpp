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

int convert (string s, int m) {
    int j = 1, c = 0;
    for(int i = m - 1; i >= 0; i--, j <<= 1)
        c += (s[i] & 1) * (j);
    return c;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    int n, m, i, j;
    string s;
    cin >> n >> m;

    int r[n];
    for(i = 0; i < n; i++)
        cin >> s, r[i] = convert(s, m);

    m = 32;
    for(i = 0; i < n - 1; i++)
        for(j = i + 1; j < n; j++)
            m = min(m, __builtin_popcount(r[i] ^ r[j]));
    cout << m << el;    
    return 0;
}

