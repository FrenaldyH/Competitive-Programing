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
    
    int n, i, a;
    cin >> n;
    vector<int> v (n + 1);
    for(i = 1; i <= n; i++)
        cin >> a, v[a] = i;
    
    a = 1;
    for(i = 1; i <= n; i++)
        if(v[i] < v[i - 1])
            a++;

    cout << a << endl;  
    return 0;
}

