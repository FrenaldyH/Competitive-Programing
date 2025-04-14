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
const int S = 20,
minf = INT_MIN, 
pinf = INT_MAX;

// Fren -> Not, Equal, AND, OR
// ASCII 0 = 48, A = 65, a = 97

// Problem : https://cses.fi/problemset/task/1653
// Solution : https://www.youtube.com/watch?v=UEkvzjsodDk

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    int n, lim, i, j, prev;
    cin >> n >> lim;
    vector<int> a(n);
    fp(i, 0, n) cin >> a[i];

    vector<pii> dp(1 << n, {1e9, 1e9});
    dp[0] = {1, 0};
    // Bitmask manipulation
    for(i = 1; i < (1 << n); i++) {
        for(j = 0; j < n; j++) 
            if((1 << j) & i) {
                prev = dp[i ^ (1 << j)].sc;
                if(prev + a[j] <= lim) {
                    dp[i] = min(dp[i], {dp[i ^ (1 << j)].fr, prev + a[j]});
                }
                else {
                    dp[i] = min(dp[i], {dp[i ^ (1 << j)].fr + 1, a[j]});
                }
            }
    }
    cout << dp[(1 << n) - 1].fr << el;
    return 0;
}