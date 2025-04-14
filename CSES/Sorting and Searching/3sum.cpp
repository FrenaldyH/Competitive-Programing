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

struct rawr {
    ll val, pos;
};

bool comp (rawr &a, rawr &b) {
    return a.val < b.val;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, x, i[3], j, sum;
    cin >> n >> x;

    vector<rawr> v (n);
    for(i[0] = 0; i[0] < n; i[0]++)
        cin >> v[i[0]].val, v[i[0]].pos = i[0] + 1;;
    sort(all(v), comp);

    for(i[0] = 0; i[0] < n - 2; i[0]++)
    {
        i[1] = i[0] + 1;
        i[2] = n - 1;

        while(i[1] < i[2])
        {
            sum = 0;
            for(j = 0; j < 3; j++)
                sum += v[i[j]].val;

            if(sum == x)
            {
                for(j = 0; j < 3; j++)
                    cout << v[i[j]].pos << " ";
                cout << endl;
                return 0;
            }
            else if(sum < x)
                i[1]++;
            else 
                i[2]--;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}

