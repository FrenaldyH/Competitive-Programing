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

const int mod = 1e9 + 7, N = 2e5, log2N = log2(2e5) + 1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q, i, j, k;
    //cout << log2N << endl;

    //Input Array
    cin >> n >> q;
    vector<vector<int>> dp 
    (n + 1, vector<int> ((int)log2(n) + 1));
    for(i = 0; i < n; i++)
        cin >> dp[i][0];

    //Dynamic Programming
    for(i = 1; i <= log2N; i++)
        for(j = 0; j <= (n - (1 << i)); j++)
            dp[j][i] = min(dp[j][i - 1], dp[j + (1 << (i - 1))][i - 1]);

    while(q--)
    {
        cin >> i >> j, i--, j--; n = j - i + 1; k = log2(n);
        cout << min(dp[i][k], dp[j - (1 << k) + 1][k]) << el;
    }
    return 0;
}

