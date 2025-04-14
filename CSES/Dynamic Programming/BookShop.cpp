#include <bits/stdc++.h>
using namespace std;

//Debugging
#define bug(x) cout << x << endl;
#define pbug(x) cout << x.fr << " " << x.sc << endl;
#define cbug(x) for(auto h : x) cout << h << " "; cout << endl;

//Shortcut
#define ms(x, y) memset(x, y, sizeof(x))
#define all(x) x.begin(), x.end()
#define sc second
#define fr first
#define el '\n'

using dd = double;
using ll = long long;
using ull = unsigned long long;
const int mod = 1e9 + 7;

struct book {int h, s;};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, x, i, j;
    cin >> n >> x;
    vector<book> v(n);
    vector<int> p(x + 1);

    for(i = 0; i < n; i++)
        cin >> v[i].h;
    for(i = 0; i < n; i++)
        cin >> v[i].s;

    for(i = 0; i < n; i++)
        for(j = x; j >= v[i].h; j--)
            p[j] = max(p[j], p[j - v[i].h] + v[i].s);
    cout << p[x] << endl;
    return 0;
}

