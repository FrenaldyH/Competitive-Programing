/**
 *    author:  FrenH
 *    created: 03.06.2025 15:55:18
 *    problem: https://cses.fi/problemset/task/3403
**/

#include <bits/stdc++.h>
using namespace std;

//Shortcut
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
pinf = INT_MAX,
mod = 1e9 + 7;

// Fren -> Not, Equal, AND, OR
// ASCII 0 = 48, A = 65, a = 97

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    int n, m, i, j;
    cin >> n >> m;
    vector<int> a(n + 1), b(m + 1);
    fp(i, 1, n + 1) cin >> a[i];
    fp(j, 1, m + 1) cin >> b[j];

    vector<vector<int>> dp(n + 1, vector<int> (m + 1));
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            if(a[i] == b[j]) 
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    i = n, j = m;
    stack<int> ans;
    while(dp[i][j]) {
        if(a[i] == b[j]) {
            ans.push(a[i]), i--, j--;
        }
        else {
            if(dp[i][j - 1] >= dp[i - 1][j]) j--;
            else                            i--;
        }
    }
    cout << ans.size() << el;
    while(!ans.empty()) {
        cout << ans.top() << ' ';
        ans.pop();
    }
    cout << el;
    return 0;
}