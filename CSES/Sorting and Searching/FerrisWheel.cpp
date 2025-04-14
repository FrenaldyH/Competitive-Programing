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

int BonBon(vector<int> v, int x)
{
    int l = 0, r = v.size() - 1, m, a = 0;
    while(l <= r)
    {
        m = (l + r) / 2;
        if(v[m] <= x)
            a = m, l = m + 1;
        else r = m - 1;
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t, n, i, j, ans = 0;
    cin >> n >> t;
    vector<int> v (n);

    for(i = 0; i < n; i++)
        cin >> v[i];
    sort(all(v));

    for(i = n - 1, j = 0; i >= j; i--)
    {
        if(v[i] + v[j] <= t)
            j++;
        ans++;
    }
    cout << ans << endl;
    
    return 0;
}

