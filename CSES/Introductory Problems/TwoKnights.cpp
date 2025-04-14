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
    
    //Aritmatika tingkat 4
    int i, s;
    cin >> s;

    if(s < 4)
    {
        vector<int> v {0, 6, 28, 96};
        for(i = 0; i < s; i++)
            cout << v[i] << endl;
        return 0;
    }

    // Dari paling bawah
    vector<ull> 
    a (s + 1),
    b (s + 0),
    c (s - 1),
    d (s - 2);

    d[1] = 42;
    for(i = 2; i < s - 2; i++)
        d[i] = d[i - 1] + 12;

    c[1] = 46;
    for(i = 2; i < s - 1; i++)
        c[i] = c[i - 1] + d[i - 1];

    b[1] = 22;
    for(i = 2; i < s; i++)
        b[i] = b[i - 1] + c[i - 1];

    a[1] = 6;
    for(i = 2; i <= s; i++)
        a[i] = a[i - 1] + b[i - 1];

    for(i = 0; i < s; i++)   
        cout << a[i] << endl;
 
    
    return 0;
}

