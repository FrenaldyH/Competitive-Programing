#include <bits/stdc++.h>
using namespace std;

//Shortcut
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

string ss;
set<int> dif;
priority_queue<int> ans;
int inQueue[S + 2], a, b, n, i;

void add(int x) {
    inQueue[x]++;
    ans.push(x);
}

void process(int x) {
    if(x == 0 || x == ss.length()) return;
    auto it = dif.find(x);
    if(it != dif.end()) {
        a = *prev(it);
        b = *next(it);
        dif.erase(it);
        inQueue[x - a]--;
        inQueue[b - x]--;   
        add(b - a);
    }
    else {
        it = dif.insert(x).first;
        a = *prev(it), b = *next(it);
        inQueue[b - a]--; 
        add(b - x);
        add(x - a);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    ms(inQueue, 0);

    cin >> ss;
    dif.insert(0), dif.insert(ss.length());
    for(i = 0; i < ss.length() - 1; i++) 
        if(ss[i] != ss[i + 1]) 
            dif.insert(i + 1);
    for(auto it = dif.begin(); next(it) != dif.end(); ++it) {
        add(*next(it) - *it);
    }

    for(cin >> n; n--;) {
        int x; cin >> x;
        process(x - 1);
        process(x);
        while(inQueue[ans.top()] <= 0) {
            ans.pop();
        }
        cout << ans.top() << ' ';
    }   
    cout << el;
    return 0;
}