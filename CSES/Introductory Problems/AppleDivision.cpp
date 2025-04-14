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
    
    ll n, i, sum = 0, ans = LLONG_MAX;
    cin >> n;
    vector<ll> v (n);
    for(i = 0; i < n; i++)
        cin >> v[i], sum += v[i];

    unordered_set<ll> s = {0};
    for(i = 0; i < n; i++)
    {
        unordered_set<ll> h;
        for(auto t : s)
            if(!s.count(v[i] + t))
                h.insert(v[i] + t);
        for(auto t : h)
            if(!s.count(t))
                s.insert(t);
    }
    for(auto t : s)
        ans = min(ans, abs(sum - 2*t));
    cout << ans << endl;
    
    return 0;
}

