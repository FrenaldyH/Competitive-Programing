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
    
    int n, m, i, a, b;
    cin >> n >> m;

    vector<bool> node (n, false);
    unordered_map<int, vector<int>> edge;
    fp(i, 0, m)
    {
        cin >> a >> b, a--, b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    queue<int> bfs; a = m = 0;
    fp(i, 0, n)
    {
        if(node[i]) continue;
        else if(edge[i].empty())
        {
            m++;
            continue;
        }
        bfs.push(i), a++;

        while(!bfs.empty())
        {
            b = bfs.front(), bfs.pop();
            for(int h : edge[b])
            {
                if(!node[h])
                    node[h] = true, bfs.push(h);
            }
        }
    }
    cout << a + (m > 1 ? 1 : 0) << el;
    return 0;
}
