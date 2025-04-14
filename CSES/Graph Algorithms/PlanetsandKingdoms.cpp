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
const int S = 1e5,
minf = INT_MIN, 
pinf = INT_MAX;

// Fren -> Not, Equal, AND, OR
// ASCII 0 = 48, A = 65, a = 97

// Tarjan's Strongly Connected Component (SCC) Algorithm (UPDATED) | Graph Theory
// https://www.youtube.com/watch?v=wUgWX0nc4NY

vector<int> 
    idx(S + 1, 0), 
    low(S + 1, 0);
vector<bool> onStk (S + 1, false);
vector<vector<int>> adj1 (
    S + 1, vector<int> ()
);
stack<int> stk;
int n, m, i, id = 1, f = 1;

unordered_map<int, int> frt;
void dfs1(int at) {
    stk.push(at), onStk[at] = 1;
    idx[at] = low[at] = id++;

    for(int to : adj1[at]) {
        if(!idx[to]) dfs1(to);
        if(onStk[to]) 
            low[at] = min(low[at], low[to]);
    }

    /* Jika buntu atau sampai di akar (low[at] == idx[at]), 
       maka kosongkan stk di atasnya */
    if(idx[at] == low[at]) {
        do { i = stk.top(), stk.pop();
            onStk[i] = false;
            low[i] = idx[at];
        } while (i != at);
        if(!frt.count(low[at])) 
            frt[low[at]] = f++;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    int a, b;
    cin >> n >> m;

    fp(i, 0, m) {
        cin >> a >> b;
        adj1[a].push_back(b);
    }

    fp(i, 1, n + 1) {
        if(!idx[i]) 
            dfs1(i);
    }

    cout << frt.size() << el;
    fp(i, 1, n + 1) 
        cout << frt[low[i]] << ' ';
    cout << el;

    return 0;
}