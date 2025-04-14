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

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    int n, m, i, a, b;
    bool cek = true;
    cin >> n >> m;

    vector<int> node (n);
    fp(i, 0, n) node[i] = 0;

    unordered_map<int, vector<int>> edge;
    fp(i, 0, m)
    {
        cin >> a >> b, a--, b--;
        edge[a].push_back(b),
        edge[b].push_back(a);
    }

    queue<int> bfs;
    for(i = 0; i < n; i++)
    {
        if(node[i]) continue;

        node[i] = 1, bfs.push(i);
        while(!bfs.empty())
        {
            b = bfs.front(), bfs.pop();
            for(auto h : edge[b])
            {
                if(!node[h])
                {
                    node[h] = 1 + (node[b] & 1);
                    bfs.push(h);
                }
                else if(node[h] == node[b]) cek = false;
            }
        }
        if(!cek)
            break;
    }
    
    if(cek)
    {
        fp(i, 0, n) cout << node[i] << " ";
        cout << el;
    }
    else cout << "IMPOSSIBLE" << el;
    return 0;
}

