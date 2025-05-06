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
minf = LLONG_MIN, 
pinf = LLONG_MAX;

// Fren -> Not, Equal, AND, OR
// ASCII 0 = 48, A = 65, a = 97

vector<ll> prefsum(S + 1);

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    prefsum[0] = 0;
    int n, a, b, i; 
    cin >> n >> a >> b;
    for(i = 1; i <= n; i++) {
        cin >> prefsum[i];
        prefsum[i] += prefsum[i - 1];
    }

    deque<ll> dq;
    ll maxsub = minf;
    for(i = a; i <= n; i++) {
        while(!dq.empty() && dq.front() < i - b) {
            dq.pop_front();
        } 
        while(!dq.empty() && prefsum[dq.back()] >= prefsum[i - a]) {
            dq.pop_back();
        }
        dq.push_back(i - a);
        maxsub = max(maxsub, prefsum[i] - prefsum[dq.front()]);
    }
    cout << maxsub << el;
    
    return 0;
}