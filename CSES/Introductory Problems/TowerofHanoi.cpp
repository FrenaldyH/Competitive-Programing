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

ll POWF(int a, int b)
{
    ll temp = 1;
    while(b > 1)
    {
        if(b & 1)
            temp *= a, b--;
        if(b) a *= a, b /= 2;
    }
    return a * temp;
}

void toh(int n, int a, int b, int c)
{
    if(n > 0)
    {
        toh(n - 1, a, c, b); // move a to b using c
        cout << a << " " << c << endl;
        toh(n - 1, b, a, c); // move b to c using a
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;  
    cout << POWF(2, n) - 1 << endl;
    toh(n, 1, 2, 3);
    
    return 0;
}

