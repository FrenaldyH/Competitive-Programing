#include <bits/stdc++.h>
using namespace std;

// Shortcut
#define fn(i, r, l) for (i = r - 1; i >= l; i--)
#define fp(i, l, r) for (i = l; i < r; i++)
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

const int N = 2000005;
int tree[2 * N], n;

void update(int k, int x) {
    k += n;
    tree[k] = x;
    k >>= 1;
    while (k >= 1) {
        tree[k] = max(tree[2 * k], tree[2 * k + 1]);
        k >>= 1;
    }
}

int query(int x) {
    if (tree[1] < x) return -1;
    int k = 1;
    while (k < n) {
        if (tree[2 * k] >= x) k <<= 1;
        else k = (k << 1) + 1;
    }
    return k - n;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);

    int m, i, x, nn;
    cin >> n >> m, nn = n;

    n = ceil(log2(n * 1.0));
    n = 1 << n;

    for (i = 0; i < nn; i++) {
        cin >> x;
        update(i, x);
    }

    while (m--) {
        cin >> x, i = query(x);
        cout << i + 1 << " ";
        if (i >= 0) {
            int y = tree[i + n] - x;
            update(i, y);
        }
    }
    cout << el;
    return 0;
}