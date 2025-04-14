#include <bits/stdc++.h>
using namespace std;

//Shortcut
#define fn(i, r, l) for(i = r - 1; i >= l; i--)
#define fp(i, l, r) for(i = l; i < r; i++)
#define ms(x, y) memset(x, y, sizeof(x))
#define all(x) x.begin(), x.end()
#define sc second
#define fr first
#define el '\n'

using dd = double;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    int n, i;
    cin >> n;

    vector<int> v(n), a(n);
    fp(i, 0, n) cin >> v[i];

    stack<int> s;
    fp(i, 0, n)
    {
        while(!s.empty() && v[s.top()] >= v[i])
        {
            s.pop();
        }
        if(s.empty())
            a[i] = 0;
        else a[i] = s.top() + 1;
        s.push(i);
    }
    fp(i, 0, n)
        cout << a[i] << " ";
    cout << el;
    return 0;
}

