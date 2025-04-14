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

int minf(int a, int b, int c) {
    return min(a, min(b, c));
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    string s[2];
    int i, j, n[2];

    fp(i, 0, 2)
        cin >> s[i],
        n[i] = s[i].length();

    int dp[n[0] + 1][n[1] + 1];
    ms(dp, 0);
    
    fp(i, 0, n[0] + 1)
    {
        fp(j, 0, n[1] + 1)
        {
            if(i == 0)
                dp[i][j] = j;
            else if(j == 0)
                dp[i][j] = i;
            else if(s[0][i - 1] == s[1][j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = minf(dp[i - 1][j - 1],
                    dp[i - 1][j], dp[i][j - 1]) + 1;
        }
    }
    
    // Display DP Table
    /* fp(i, 0, n[0] + 1)
    {
        fp(j, 0, n[1] + 1)
            cout << dp[i][j] << " ";
        cout << el;
    } */
    cout << dp[n[0]][n[1]] << el;
    return 0;
}

