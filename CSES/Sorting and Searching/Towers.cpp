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

     multiset<int> s;
    int n, k;
    
    cin >> n;
    while(n--) {
        cin >> k;
        auto r = s.upper_bound(k);
        if(r != s.end() && !s.empty()) 
            s.erase(r);
        s.insert(k);
    }
    
    cout << s.size() << endl;
    
    return 0;
}

