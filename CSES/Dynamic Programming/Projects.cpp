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
const int S = 2e5,
minf = INT_MIN, 
pinf = INT_MAX;

// Fren -> Not, Equal, AND, OR
// ASCII 0 = 48, A = 65, a = 97

bool comp(vector<ll> &a, vector<ll> &b) {
    return a[1] < b[1];
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    int n, i, j;
    cin >> n;
    
    vector<vector<ll>> tup (n, vector<ll> (3));
    fp(i, 0, n) fp(j, 0, 3) cin >> tup[i][j];
    sort(all(tup), comp);

    map<ll, ll> dp {{0, 0}};
    for(i = j = 0; i < n; i++) {
        auto it = dp.upper_bound(tup[i][0] - 1); --it;
        if(dp[j] < tup[i][2] + it->second) {
            j = tup[i][1];
            dp[j] = tup[i][2] + it->second;
        }
    }
    cout << dp[j] << el;


    
    return 0;
}