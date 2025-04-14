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
    
    int n, i;
    cin >> n;
    
    unordered_set<int> s1, s2 = {0};
    while(n--)
    {
        cin >> i; s1 = {};
        for(auto h : s2)
            s1.insert(i + h);
        
        for(auto h : s1)
            if(!s2.count(h))
                s2.insert(h);
    }

    vector<int> p (all(s2));
    sort(all(p));
    cout << p.size() - 1 << endl;
    for(i = 1; i < p.size(); i++)
        cout << p[i] << " ";
    cout << endl;
}

