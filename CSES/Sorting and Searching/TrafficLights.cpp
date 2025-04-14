#include <bits/stdc++.h>
using namespace std;

//Shortcut
#define fn(i, r, l)     for(i = r - 1; i >= l; i--)
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
pinf = INT_MAX;

// Fren -> Not, Equal, AND, OR
// ASCII 0 = 48, A = 65, a = 97

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    map<int, int> 
        mp1 = {{n, n}}, 
        mp2 = {{n, 1}};

    while(m--) {
        cin >> n;
        auto it1 = mp1.lower_bound(n);
        mp2[it1->fr - n]++;
        
        if(it1 != mp1.begin()) {
            auto it2 = prev(it1);
            mp2[n - it2->fr]++;
            mp1[n] = n - it2->fr;
        }
        else {
            mp2[n]++, mp1[n] = n;
        }
        
        mp2[it1->sc]--;
        if(!mp2[it1->sc])
            mp2.erase(it1->sc);
        mp1[it1->fr] = it1->fr - n;
        cout << mp2.rbegin()->fr << ' ';
    }
    cout << el;

    /* for(auto it : mp1) {
        cout << it.fr << ' ' << it.sc << el;
    } */
    /* for(auto it : mp2) {
        cout << it.fr << ' ' << it.sc << el;
    } */
    return 0;
}