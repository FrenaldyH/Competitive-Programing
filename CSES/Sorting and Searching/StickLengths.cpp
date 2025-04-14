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
    
    ll n, i, m, ans = 0;
    cin >> n;
    vector<int> v(n);
    for(i = 0; i < n; i++)
        cin >> v[i];
    sort(all(v));

    if(n & 1)
        m = v[n >> 1];
    else m = (v[(n >> 1) - 1] + v[n >> 1]) / 2;
    for(i = 0; i < n; i++)
        ans += abs(v[i] - m);
    cout << ans << endl;
    
    return 0;
}

