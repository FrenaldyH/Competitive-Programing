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

struct node {
    int v, l, r;
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    unordered_map<int, int> hash;
    int n, m, i, f, b, x;

    cin >> n >> m;
    vector<node> lk(n);
    fp(i, 0, n) {
        cin >> lk[i].v;
        lk[i].l = i - 1;
        lk[i].r = i + 1;
        hash[lk[i].v] = i;

        if(!i) f = lk[i].v;
        else if(i == n - 1) 
            b = lk[i].v;
    }
    lk[n - 1].r = -1;

    char op;
    while(m--) {
        cin >> op >> x;
        if(op == 'A') {
            hash[x] = n, n++;

            lk.push_back({x, -1, hash[f]});
            lk[hash[f]].l = hash[x], f = x;
        }
        else if(x ^ f) {
            lk[hash[f]].l = hash[b];
            lk[lk[hash[x]].l].r = -1;
            
            lk[hash[b]].r = hash[f];
            b = lk[lk[hash[x]].l].v;

            lk[hash[x]].l = -1, f = x;
        }
    }

    cout << n << el, f = hash[f];
    while(f >= 0) {
        cout << lk[f].v << " ", f = lk[f].r;
    }
    return 0;
}
