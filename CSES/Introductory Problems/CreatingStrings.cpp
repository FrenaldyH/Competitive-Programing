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

string p;
vector<bool> c(8);
queue<string> ans;
unordered_set<string> h;
void rec(string s)
{
    if(s.length() == p.length())
    {
        if(!h.count(p))
            ans.push(p);
        h.insert(p);
    }
    else
    {
        for(int i = 0; i < s.length(); i++)
        {
            if(c[i]) continue;
            c[i] = true;
            p += s[i];
            rec(s);
            c[i] = false;
            p.pop_back();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string in; cin >> in; sort(all(in));
    rec(in);

    cout << ans.size() << endl;
    while(!ans.empty())
    {
        cout << ans.front() << endl;
        ans.pop();
    }
    
    return 0;
}

