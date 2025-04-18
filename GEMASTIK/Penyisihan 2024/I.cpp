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
    
    ll n, m, i, j, sum, k;
    cin >> n >> m;

    vector<ll> v(n); sum = 0;
    fp(i, 0, n) 
        cin >> v[i], sum += v[i];
    sort(all(v), greater());
    
    // Precompute
    for(i = 0; i < n; i++)
        v[i] >>= 1LL;
    vector<ll> ans(200002);
    for(i = 2; i < 200002; i++)
    {
        ans[i] = 0;
        for(j = i - 1; j < n; j += i)
            ans[i] += v[j];
        ans[i] = sum - ans[i];
    }

    while(m--) {
        cin >> i, cout << ans[i] << el;
    }
    return 0;
}
