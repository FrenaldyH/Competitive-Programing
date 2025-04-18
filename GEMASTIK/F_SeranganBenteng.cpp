#include <iostream>
#include <unordered_map>
using namespace std;

#define el '\n'
using ll = long long;
ll x, a, b;

ll backtrack(ll x, unordered_map<ll, ll> &memo) {
    if(x <= 1) return x;
    if(memo.count(x)) return memo[x];
    return memo[x] = min(x, min((x & 1LL) + a + backtrack(x >> 1LL, memo), (x % 3LL) + b + backtrack(x / 3LL, memo)));
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    int tc;
    cin >> tc >> a >> b;
    while(tc--) {
        unordered_map<ll, ll> memo;
        cin >> x; cout << backtrack(x, memo) << el;
    }
    return 0;
}
