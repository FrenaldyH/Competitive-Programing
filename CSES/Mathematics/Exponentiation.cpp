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

ll power(ll a, ll b)
{
    ll t = 1;
    while(b > 1)
    {
        if(b & 1)
            t *= a, b--;
        if(b) a *= a, b /= 2;
        a = (a % mod),
        t = (t % mod);
    }
    return (b ? ((a * t) % mod) : 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, a, b;
    cin >> n;
    while(n--)
    {
        cin >> a >> b;
        cout << power(a, b) << el;
    }
    
    return 0;
}

