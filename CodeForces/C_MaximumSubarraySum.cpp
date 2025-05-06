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
const ll S = 2e5,
minf = -2e12, 
pinf =  2e12;

// Fren -> Not, Equal, AND, OR
// ASCII 0 = 48, A = 65, a = 97

/**
 *      Soal CF yang sulit (05.05.2025) -> (06.05.2025)
 *      https://codeforces.com/contest/2107/problem/C
**/

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    string s;
    int tc, n, i, pos;
    ll cursum, maxsum, maxpref, maxsuff, k;
    vector<ll> a(S);

    for(cin >> tc; tc--;) {
        cin >> n >> k >> s;

        pos = -1;
        fp(i, 0, n) {
            cin >> a[i];
            if(s[i] == '0') {
                a[i] = minf;
                pos = i;
            }
        }

        cursum = maxsum = minf;
        fp(i, 0, n) {
            cursum = max(cursum + a[i], a[i]);
            maxsum = max(maxsum, cursum);
        }
        if(maxsum > k || (maxsum != k && pos < 0)) {
            cout << "No\n";
            continue;
        }
        if(pos >= 0) {
            maxsum = cursum = 0;
            for(i = pos + 1; i < n; i++) {
                cursum += a[i];
                maxsum = max(maxsum, cursum);
            }
            maxpref = maxsum;

            maxsum = cursum = 0;
            for(i = pos - 1; i >= 0; i--) {
                cursum += a[i];
                maxsum = max(maxsum, cursum);
            }
            maxsuff = maxsum; 
            a[pos] = k - maxsuff - maxpref;
        }

        cout << "Yes\n";
        for(i = 0; i < n; i++) {
            cout << a[i] << (i + 1 < n ? ' ' : '\n');
        }
    }
    
    return 0;
}