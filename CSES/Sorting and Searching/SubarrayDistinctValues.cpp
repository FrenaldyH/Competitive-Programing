#include <bits/stdc++.h>
using namespace std;

//Shortcut
#define fn(i, r, l) for(i = r - 1; i >= l; i--)
#define fp(i, l, r) for(i = l; i < r; i++)
#define ms(x, y) memset(x, y, sizeof(x))
#define all(x) x.begin(), x.end()
#define sc second
#define fr first
#define el '\n'

using dd = double;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

// Global variabel
const int 
minf = INT_MIN, 
pinf = INT_MAX;

// Fren -> Not, Equal, AND, OR
// ASCII 0 = 48, A = 65, a = 97

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    int n, k, i, x; ll ans = 0;
    cin >> n >> k;

    queue<int> q;
    map<int, int> mp;
    for(i = 1; i <= n; i++) {
        cin >> x, q.push(x), mp[x]++;
        while(mp.size() > k && !q.empty()) {
            x = q.front(), q.pop();
            mp[x]--; 

            if(!mp[x]) mp.erase(x);
        }
        ans += q.size();
    }
    cout << ans << el;
    return 0;
}