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
const int S = 1e5,
minf = INT_MIN, 
pinf = INT_MAX,
mod = 1e9 + 7;

// Fren -> Not, Equal, AND, OR
// ASCII 0 = 48, A = 65, a = 97

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    int n, x, i, sum = 0;
    map<int, int> mp;
    pii maxp, minp;

    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> x;
        sum += x;
        mp[x]++;

        if(i > 1) {
            if(maxp.fr < x) 
                maxp = {x, i};
            if(minp.fr > x)
                minp = {x, i};
        } else maxp = minp = {x, i};
    }

    if(mp.size() > 3 || sum % n != 0 || (mp.size() > 1 && (mp.begin()->sc > 1 || mp.rbegin()->sc > 1)) || mp.begin()->fr + mp.rbegin()->fr != sum / n * 2) 
        cout << "TIDAK SESUAI" << el;
    else if(mp.size() == 1) 
        cout << "SESUAI" << el;
    else cout << sum / n - minp.fr << ' ' << maxp.sc << ' ' << minp.sc << el;
    return 0;
}
