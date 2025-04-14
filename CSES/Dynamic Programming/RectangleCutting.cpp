#include <bits/stdc++.h>
using namespace std;

//Debugging
#define bug(x) cout << x << endl;
#define pbug(x) cout << x.fr << " " << x.sc << endl;
#define cbug(x) for(auto h : x) cout << h << " "; cout << endl;

//Shortcut
#define ms(x, y) memset(x, y, sizeof(x))
#define all(x) x.begin(), x.end()
#define sc second
#define fr first
#define el '\n'

using dd = double;
using ll = long long;
using ull = unsigned long long;

const int mod = 1e9 + 7;
vector<vector<int>> dp (500 + 1, vector<int> (500 + 1, 1e9));

/* int rec(int x, int y)
{
    if(dp[x][y] >= 0)
        return dp[x][y];
    
    if(x == y)
        dp[x][y] = 0;
    else 
    {
        int a, b;
        if(x < y)
            a = x, b = y;
        else
            a = y, b = x;
        dp[x][y] = 1 + rec(a, a) + rec(a, b - a);
    }
    return dp[x][y];
} */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int a, b, i, j, k; cin >> a >> b;
    for(i = 0; i <= a; i++)
    {
        for(j = 0; j <= b; j++)
        {
            if(i == j) dp[i][j] = 0;
            else
            {
                for(k = 1; k < i; k++)
                    dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
                for(k = 1; k < j; k++)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
            }
        }
    }
    cout << dp[a][b] << endl;
    return 0;
}

