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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, x, i, j;
    cin >> n >> x;

    vector<int> v(n), dp(x + 1);
    for(i = 0; i < n; i++)
        cin >> v[i];
    sort(all(v)), dp[0] = 1;

    for(i = 0; i < n; i++)
        for(j = v[i]; j <= x; j++)
            dp[j] = (dp[j] + dp[j - v[i]]) % mod; 
    cout << dp[x] << endl;
    return 0;
}

