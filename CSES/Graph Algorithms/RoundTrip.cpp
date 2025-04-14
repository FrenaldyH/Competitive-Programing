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

// Global variabel
const int S = 1e5,
minf = INT_MIN, 
pinf = INT_MAX;

// Fren -> Not, Equal, AND, OR
// ASCII 0 = 48, A = 65, a = 97

vector grph (S + 1, vector<int> ({}));
vector<bool> vis (S + 1);

stack<int> cyc, ans;
bool dfs(int n, int p) {
    vis[n] = true;
    for(int ch : grph[n]) {
        cyc.push(ch);
        if(!vis[ch]) {
            if(dfs(ch, n)) 
                return true;
        }
        else if(ch != p) 
            return true;
        cyc.pop();
    }
    return false;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    int n, m, a, b, i;
    cin >> n >> m;

    fp(i, 0, m) {
        cin >> a >> b;
        grph[a].push_back(b);
        grph[b].push_back(a);
    }


    for(i = 1; i <= n; i++) {
        if(vis[i]) continue;

        cyc.push(i);
        if(dfs(i, 0)) {
            a = cyc.top(), b = 0; 
            while(!cyc.empty()) {
                ans.push(cyc.top()), cyc.pop();
                if(ans.top() == a) {
                    if(b) break; b++;
                }
            }
            
            cout << ans.size() << el;
            while(!ans.empty()) {
                cout << ans.top() << ' ', ans.pop();
            }
            cout << el;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << el;
    return 0;
}