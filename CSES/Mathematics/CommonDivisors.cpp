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
const int S = 1e6,
minf = INT_MIN, 
pinf = INT_MAX;

// Fren -> Not, Equal, AND, OR
// ASCII 0 = 48, A = 65, a = 97

int divisor[S + 1];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    ms(divisor, 0);
    int n, i, a, up;
    
    for(cin >> n; n--;) {
        cin >> a;
        up = sqrt(a);
        for(i = 1; i <= up; i++) {
            if(a % i == 0) {
                divisor[i]++;
                if(i != a/i) 
                    divisor[a/i]++;
            }
        }
    }

    for(i = S; i >= 1; i--) {
        if(divisor[i] > 1) {
            cout << i << el;
            break;
        }
    }
    
    return 0;
}