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

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    int n, i, j, c = 0;
    cin >> n;

    vector<int> a(n), b(n);
    fp(i, 0, n) cin >> a[i];
    fp(i, 0, n) cin >> b[i];

    for(i = 1; i < n; i++)
        a[i] = min(a[i], a[i - 1]);
    for(i = n - 2; i >= 0; i--)
        b[i] = max(b[i], b[i + 1]);

    for(i = 0; i < n - 2; i++)
        c = max(c, b[i + 2] - a[i]);

    if(c) cout << c << el;
    else cout << "tidak mungkin" << el;
    return 0;
}
