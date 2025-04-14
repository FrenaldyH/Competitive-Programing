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

struct c {int t, l, b = -1;};

bool comp1(c &a, c &b)
{
    if(a.t == b.t)
        return a.l < b.l;
    return a.t > b.t;
}

bool comp2(c &a, c &b)
{
    return a.l < b.l;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, i, j;
    cin >> n >> m;

    // Sesuatu container yang enak untuk hapus ditengah tengah 
    // dan bisa upper bound

    multiset<int> s;
    for(i = 0; i < n; i++)
        cin >> j, s.insert(j);
    
    while(m--)
    {
        cin >> j;
        multiset<int>::iterator r = s.upper_bound(j);
        if(r == s.begin())
            cout << -1 << endl;
        else 
        {
            r--, cout << (*r) << endl;
            s.erase(r);
        }
    }
    return 0;
}

