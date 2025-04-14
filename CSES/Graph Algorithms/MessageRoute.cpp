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
const int INF = INT_MAX;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    int n, m, i, a, b;
    cin >> n >> m;

    vector<pii> node(n);
    unordered_map<int, vector<int>> edge;
    for(i = 0; i < m; i++)
    {
        cin >> a >> b, a--, b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    fp(i, 0, n) node[i] = {INF, -1};
    queue<int> q; q.push(0);
    node[0] = {0, 0};

    while(!q.empty())
    {
        b = q.front(), q.pop();
        for(int h : edge[b])
        {
            if(node[h].fr > node[b].fr + 1)
            {
                node[h] = {node[b].fr + 1, b};
                q.push(h);
            }
        }
    }

    if(node[n - 1].sc < 0)
        cout << "IMPOSSIBLE" << el;
    else
    {
        stack<int> ans; b = n - 1; ans.push(b);
        while(b)
        {
            b = node[b].sc;
            ans.push(b);
        }
        cout << ans.size() << el;
        while(!ans.empty()) {
            cout << ans.top() + 1 << " ", ans.pop();
        } cout << el;
    }
    return 0;
}

