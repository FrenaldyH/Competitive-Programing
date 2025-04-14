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
    
    int n, i, j, ans, sum;
    cin >> n;
    
    vector<int> l(n), r(n);
    for(i = 0; i < n; i++)
        cin >> l[i] >> r[i];

    sort(all(l)), sort(all(r)), ans = sum = 0;
    for(i = 0, j = 0; i < n && j < n;)
    {
        if(l[i] < r[j])
            sum++, i++;
        else 
            sum--, j++;
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}

