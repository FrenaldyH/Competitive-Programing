#include <bits/stdc++.h>
using namespace std;
//#define bug_for(x) for(auto h : x) cout << h << " "; cout << endl;
#define ufor(a, b, c, d) for(a = b; a < c ; a += d)
#define dfor(a, b, c, d) for(a = b; a >= c; a -= d)
#define bfor(x, y) for(x = 0; x < y; x++)
#define all(x) x.begin(), x.end()
#define el '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, i; 
    cin >> n;
    vector<int> v(n - 1);
    bfor(i, n - 1)
        cin >> v[i];
    sort(all(v));
    bfor(i, n - 1)
    {
        if(v[i] != i + 1)
        {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << n << endl;
    return 0;
}
//Jangan Lupa Endl;