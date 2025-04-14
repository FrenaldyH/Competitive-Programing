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
    
    ll n, x, i[4], j, sum;
    cin >> n >> x;

    vector<rawr> v (n);
    for(j = 0; j < n; j++)
        cin >> v[j].val, v[j].pos = j + 1;
    sort(all(v), comp);

    for(i[0] = 0; i[0] < n - 3; i[0]++)
    {
        for(i[1] = i[0] + 1; i[1] < n - 2; i[1]++)
        {
            i[2] = i[1] + 1;
            i[3] = n - 1;
            while(i[2] < i[3])
            {
                sum = 0;
                for(j = 0; j < 4; j++)
                    sum += v[i[j]].val;

                if(sum == x)
                {
                    for(j = 0; j < 4; j++)
                        cout << v[i[j]].pos << " ";
                    cout << endl;
                    return 0;
                }
                else if(sum < x)
                    i[2]++;
                else 
                    i[3]--;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}

