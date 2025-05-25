#include <bits/stdc++.h>
using namespace std;

#define ms(x, y) memset(x, y, sizeof(x))
#define all(x) x.begin(), x.end()
#define sc second
#define fr first
#define el '\n'

using ll = long long;
using ull = unsigned long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, a, i, l, r;
    cin >> n;
    
    unordered_set<int> s;
    while(n--) {cin >> a, s.insert(a);}
    vector<int> v (all(s));
    sort(all(v));

    //for(int h : v) cout << h << " "; cout << endl;

    n = v.size(), l = r = i = 0;
    for(i; i < n - 1; i++)
    {
        if(v[i] == v[i + 1] - 1)
            r++;
        else 
        {
            if(l == r)
                cout << v[i];
            else cout << v[l] <<"-"<< v[r];
            if(r != n - 1)
                cout << ",", l = r = i + 1;
        }
        if(r >= n - 1)
        {
            if(l == r)
                cout << v[r];
            else cout << v[l] <<"-"<< v[r];
        }
    }
    if(n == 1) cout << v[0];
    cout << el;
    return 0;   
}

/*
    13
1 2 3 1 1 2 6 6 2 5 7 10 7

    3
30 20 10

    3 
3 2 1


*/
