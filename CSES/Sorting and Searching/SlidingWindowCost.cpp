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
const int S = 1e5,
minf = INT_MIN, 
pinf = INT_MAX;

// Fren -> Not, Equal, AND, OR
// ASCII 0 = 48, A = 65, a = 97

ll sum_low, sum_upp, med;
multiset<int> low, upp;
int n, k, x, a, b;
queue<int> q;

void balance(int max_low, int min_upp) {
    sum_low -= (max_low - min_upp);
    sum_upp += (max_low - min_upp);
    low.erase(low.find(max_low));
    upp.erase(upp.find(min_upp));
    low.insert(min_upp);
    upp.insert(max_low);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    for(cin >> n >> k; n--;) {
        cin >> x, q.push(x);

        if(q.size() > k) {
            auto it = low.find(q.front());
            if(it != low.end()) {
                low.erase(it);
                sum_low -= q.front();
            }
            else {
                upp.erase(upp.find(q.front()));
                sum_upp -= q.front();
            }
            q.pop();
        }

        if(low.size() <= upp.size()) {
            low.insert(x);
            sum_low += x;
        }
        else {
            upp.insert(x);
            sum_upp += x;
        }

        if(!low.empty() && !upp.empty()) {
            a = *low.rbegin();
            b = *upp. begin();
            if(a > b) { balance(a, b); }
        }

        if(q.size() == k) {
            med = *low.rbegin();
            cout << med * low.size() - sum_low + sum_upp - med * upp.size() << ' ';
        }
    }
    cout << el;
    
    return 0;
}