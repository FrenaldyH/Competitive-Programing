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
    
    int n, i, g;
    cin >> n;

    vector<int> tiang(n);
    fp(i, 0, n) cin >> tiang[i];
    sort(all(tiang));

    g = 0;
    fp(i, 1, n) 
        g = max(g, tiang[i] - tiang[i - 1]);
    cout << g << el << tiang.back() - tiang.front() << el;
    return 0;
}
