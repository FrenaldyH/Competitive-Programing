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

// 5 10 15 20 25 -> 6, bukan 5
int solve(int x)
{
    if(x) return x / 5 + solve(x / 5);
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int x; cin >> x;
    cout << solve(x) << endl;
    
    return 0;
}

