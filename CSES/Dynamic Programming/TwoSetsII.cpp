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

int solve(int n) 
{
    if((n * (n + 1)) % 4)
        return 0;
    
    int nn, i, j, t;
    nn = (n * (n + 1)) >> 2;
    vector<int> dp(nn + 1, 0);

    dp[0] = 1;
    fp(i, 1, n)
    {
        fn(j, nn, 0)
        {
            t = i + j;
            if(t > nn)
                continue;

            dp[t] = (dp[t] + dp[j]) % mod;
        }
    }
    return dp[nn];
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    int n; cin >> n;
    cout << solve(n) << el;
    
    return 0;
}

