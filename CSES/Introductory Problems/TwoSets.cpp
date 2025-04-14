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
    
    queue<int> q[2];
    int n, i;
    cin >> n;

    if((n % 4) == 0)
    {
        for(i = 0; i < (n >> 1); i++)
            q[(i & 1)].push(n - i),
            q[(i & 1)].push(i + 1);
    } else
    if((n % 4) == 3)
    {
        for(i = 0; i < (n >> 1); i++)
            q[(i & 1)].push(n - i - 1),
            q[(i & 1)].push(i + 1);
        q[1].push(n);
    } 
    else
    {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for(i = 0; i < 2; i++)
    {
        cout << q[i].size() << endl;
        while(!q[i].empty())
        {
            cout << q[i].front() << " ";
            q[i].pop();
        }
        cout << endl;
    }
    return 0;
}

