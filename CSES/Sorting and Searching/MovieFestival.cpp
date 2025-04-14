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

bool comp(pair<int, int> &a, pair<int, int> &b)
{
    return a.sc < b.sc;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, i, j, ans = 1;
    cin >> n;
    vector<pair<int, int>> v(n);
    for(i = 0; i < n; i++)
        cin >> v[i].fr >> v[i].sc;
    sort(all(v), comp);

    for(i = 1, j = 0; i < n; i++)
        if(v[i].fr >= v[j].sc)
            j = i, ans++;
    cout << ans << endl;
    
    return 0;
}

