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

bool comp(vector<int> &a, vector<int> &b) {
    return a[0] < b[0];
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    int n, i, j = 1;
    cin >> n;

    vector<vector<int>> v(n, vector<int> (3));
    fp(i, 0, n) {
        v[i][2] = i;
        cin >> v[i][0] >> v[i][1];
    }
    sort(all(v), comp);

    /* fp(i, 0, n) 
        cout << v[i][0] << ' ' << v[i][1] << el; */

    priority_queue<pii, vector<pii>, 
        greater<pii>> minheap;
    vector<int> a(n);
    fp(i, 0, n) {
        if(!minheap.empty() && minheap.top().fr < v[i][0]) {
            a[v[i][2]] = minheap.top().sc, minheap.pop();
            minheap.push({v[i][1], a[v[i][2]]});
        }
        else {
            minheap.push({v[i][1], j});
            a[v[i][2]] = j, j++;
        }
    }

    cout << j - 1 << el;
    fp(i, 0, n) cout << a[i] << ' ';
    cout << el;
    return 0;
}