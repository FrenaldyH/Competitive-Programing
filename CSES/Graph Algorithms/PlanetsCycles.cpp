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
const int S = 2e5,
minf = INT_MIN, 
pinf = INT_MAX;

// Fren -> Not, Equal, AND, OR
// ASCII 0 = 48, A = 65, a = 97

vector<int> 
    des (S + 1),
    con (S + 1);
vector<bool> 
    vis (S + 1, 0),
    ons (S + 1, 0);
stack<int> stk;

int cyc;
void dfs(int n) {
    con[n] = vis[n] = ons[n] = 1;
    stk.push(n);
    if(!vis[des[n]]) {
        dfs(des[n]);
        con[n] += con[des[n]];
    }
    else {
        if(ons[des[n]]) 
            cyc = des[n];
        else con[n] += con[des[n]];
    }
    ons[n] = 0;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    int n, i, a;
    cin >> n;

    fp(i, 1, n + 1) 
        cin >> a, des[i] = a;
    
    fp(i, 1, n + 1) {
        if(!vis[i]) {
            cyc = 0;
            dfs(i);

            if(cyc) {
                // cout << i << ' ' << cyc << ' ' << stk.top() << el;
                while(!stk.empty()) {
                    if(stk.top() != cyc && cyc) {
                        con[stk.top()] = con[cyc];
                    }
                    else cyc = 0;
                    stk.pop();
                }
            }
        }
    }
    fp(i, 1, n + 1) 
        cout << con[i] << ' ';
    cout << el;

    return 0;
}