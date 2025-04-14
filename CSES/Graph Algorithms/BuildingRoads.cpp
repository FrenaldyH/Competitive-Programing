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

int find (vector<int> &l, int y) {
    if(y ^ l[y]) return l[y] = find(l, l[y]);
    return l[y];
}

void unite (vector<int> &l, int a, int b) {
    a = find(l, a);
    b = find(l, b);
    if(a > b) swap(a, b);
    l[b] = a;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    int n, m, i, a, b;
    cin >> n >> m;

    vector<int> link (n), ans;
    fp(i, 0, n) link[i] = i;
    fp(i, 0, m) 
    {
        cin >> a >> b, a--, b--;
        unite(link, a, b);
    }

    vector<bool> vis(n, false);
    fp(i, 0, n)
    {
        if(vis[i]) continue;

        b = i;
        while(link[b] ^ b)
        {
            vis[b] = true;
            b = link[b];
        }
        
        if(!vis[b]) ans.push_back(b + 1);
        vis[b] = true;
    }
    
    a = ans.size();
    cout << a - 1 << el;
    for(i = 1; i < a; i++)
        cout << ans[i - 1] << " " << ans[i] << el;
    return 0;
}

