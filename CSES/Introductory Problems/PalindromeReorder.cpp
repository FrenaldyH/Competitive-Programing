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
    
    int i, c, a[26];
    string s;
    cin >> s;
    ms(a, 0);
    c = 0;

    for(i = 0; i < s.length(); i++)
        a[(int)s[i] - 65]++;
    for(i = 0; i < 26; i++)
        if(a[i] & 1) c++;
    //cbug(a);
    
    if(c > 1) cout << "NO SOLUTION" << endl;
    else
    {
        stack<char> q;
        for(i = 0; i < 26; i++)
        {
            if(a[i] & 1)
            {
                c = i;
                continue;
            }
            while(a[i])
            {
                cout << char(65 + i), q.push(char(65 + i));
                a[i] -= 2;
            }
        }
        while(a[c])
        {
            cout << char(65 + c), a[c]--;
        }
        while(!q.empty())
        {
            cout << q.top(), q.pop();
        }
        cout << endl;
    }
    
    return 0;
}

