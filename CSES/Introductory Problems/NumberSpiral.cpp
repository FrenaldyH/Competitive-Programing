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
    
    ull t, x, y, z, ans;
    cin >> t;
    while(t--)
    {
        cin >> y >> x;
        z = max(x, y);
        ans = z * (z - 1) + 1;

        if(z & 1)
        {
            if(x >= y)
                ans += (x - y);
            else
                ans -= (y - x);
        }
        else
        {
            if(x >= y)
                ans -= (x - y);
            else
                ans += (y - x);
        }
        cout << ans << el;
    }
    return 0;
}

