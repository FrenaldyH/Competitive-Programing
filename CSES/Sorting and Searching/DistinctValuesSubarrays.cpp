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
pinf = INT_MAX;

// Fren -> Not, Equal, AND, OR
// ASCII 0 = 48, A = 65, a = 97

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    int tc, x;
    set<int> st;
    queue<int> q;
    ll ans = 0;
    for(cin >> tc; tc--;) {
        cin >> x, q.push(x);
        while(!q.empty() && st.count(x)) {
            st.erase(q.front());
            q.pop();
        }
        st.insert(x);
        ans += q.size();
    }
    cout << ans << el;
    return 0;
}