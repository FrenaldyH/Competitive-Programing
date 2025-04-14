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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k, i, j;
    cin >> n >> k;
    vector<int> c(k + 1, 1e7), v(n);
    for(i = 0; i < n; i++)  
    {
        cin >> v[i];
        if(v[i] <= k)
            c[v[i]] = 1;
    }

    sort(all(v));
    for(j = v[0]; j <= k; j++)
    {
        for(i = 0; i < n; i++)
        {
            if(j < v[i])
                break;
            c[j] = min(c[j], c[j - v[i]] + 1);
        }
    }
    cout << (c[k] == 1e7 ? -1 : c[k]) << endl;
    return 0;
}

