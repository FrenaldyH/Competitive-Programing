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
const int S = 1e7,
minf = INT_MIN, 
pinf = INT_MAX,
mod = 1e9 + 7;

// Fren -> Not, Equal, AND, OR
// ASCII 0 = 48, A = 65, a = 97

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    int n, i, j, k, temp, ans;
    vector<bool> soe(S + 1, true);
    for(i = 2; i * i < S; i++) 
        if(soe[i])
            for(j = i * i; j <= S; j += i)
                soe[j] = false;

    vector<int> prime;
    for(i = 2; i < S; i++) 
        if(soe[i]) prime.push_back(i);

    cin >> n;
    vector<int> x(n);
    for(i = 0; i < n; i++) {
        cin >> x[i], temp = 1;
        if(soe[x[i]]) continue;
        for(j = 0; j < prime.size() && prime[j] * prime[j] <= x[i]; j++) {
            for(k = 0; x[i] % prime[j] == 0; k++, x[i] /= prime[j]);
            temp *= ((k & 1) ? prime[j] : 1);
        }
        x[i] *= temp;
    }
    sort(all(x));
    
    ans = 1;
    for(i = 1; i < n; i++) 
        if(x[i] != x[i - 1]) 
            ans++;
    cout << (ans == n ? -1 : ans + 1) << el;

    return 0;
}
