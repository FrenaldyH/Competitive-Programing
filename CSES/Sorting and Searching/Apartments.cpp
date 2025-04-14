#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

//Ordered_set
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

//Ordered_multiset
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_multiset;

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
    
    int n, m, k, i, j, t1, t2, ans = 0;
    cin >> n >> m >> k;

    vector<int> a(n), b(m);
    for(i = 0; i < n; i++)
        cin >> a[i];
    for(i = 0; i < m; i++)
        cin >> b[i];

    sort(all(a)),
    sort(all(b));

    for(i = j = 0; i < n && j < m;)
    {
        t1 = b[j] + k,
        t2 = b[j] - k;

        if(a[i] <= t1 && a[i] >= t2)
            i++, j++, ans++;
        else if(a[i] > t1)
            j++;
        else if(a[i] < t2)  
            i++;
    }    
    cout << ans << endl;
    return 0;
}

