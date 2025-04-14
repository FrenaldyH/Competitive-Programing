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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int i, j, n; cin >> n;
    vector<int> v (int(1e6)); v[1] = 1;
    for(i = 2; i <= 6; i++)
        v[i] = v[i - 1] << 1;
    for(i = 7; i <= n; i++)
    {
        for(j = 1; j <= 6; j++)
            v[i] += v[i - j], 
            v[i] = (v[i] % mod);
    }
    cout << v[n] << endl;
}

