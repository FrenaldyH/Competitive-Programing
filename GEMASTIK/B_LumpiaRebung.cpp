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

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    ll n, cut, t;
    deque<ll> dq(1);
    cin >> n >> dq[0];

    while(n--)
    {
        cin >> cut; dq[cut - 1] >>= 1;
        dq.insert(dq.begin() + cut, dq[cut - 1]);
    }
    for(ll h : dq)
        cout << h << " ";
    cout << el;
    return 0;
}
