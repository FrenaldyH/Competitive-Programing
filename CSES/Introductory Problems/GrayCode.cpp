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

string p, b = "01";
void rec(int n)
{
    if(p.length() == n)
    {
        cout << p.front();
        for(int i = 1; i < p.length(); i++)
            cout << (p[i - 1] == p[i] ? '0' : '1');
        cout << endl;
    }
    else
    {
        for(int i = 0; i <= 1; i++)
        {
            p += b[i];
            rec(n);
            p.pop_back();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n; rec(n);
    
    return 0;
}

