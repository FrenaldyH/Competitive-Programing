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

bool fill(vector<vector<bool>> &v, int i, int j, int n, int m)
{
    if(i >= n || j >= m || i < 0 || j < 0 || !v[i][j]) 
        return 0;
    v[i][j] = false;
    return 
    fill(v, i + 1, j, n, m),
    fill(v, i, j + 1, n, m),
    fill(v, i - 1, j, n, m),
    fill(v, i, j - 1, n, m);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, i, j, a = 0;
    cin >> n >> m;
    char c;

    vector<vector<bool>> v (n, vector<bool> (m));
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            cin >> c, v[i][j] = (c == '.' ? 1 : 0);

    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            if(v[i][j])
                a++, fill(v, i, j, n, m);
    
    cout << a << endl;
            
    
    return 0;
}

