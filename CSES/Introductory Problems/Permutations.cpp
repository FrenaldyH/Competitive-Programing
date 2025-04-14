#include <bits/stdc++.h>
using namespace std;
//#define bug_for(x) for(auto h : x) cout << h << " "; cout << endl;
#define up_for(a, b, c, d) for(a = b; a < c ; a += d)
#define do_for(a, b, c, d) for(a = b; a >= c; a -= d)
#define basic_for(x, y) for(x = 0; x < y; x++)
#define CIN4(a, b, c, d) cin >> a >> b >> c >> d;
#define CIN3(a, b, c) cin >> a >> b >> c;
#define all(x) x.begin(), x.end()
#define gl(x) getline(cin, x);
#define it ::iterator
#define s second
#define f first
#define el '\n'
using sh = short;
using ss = string;
using dd = double;
using ll = long long;
using b_64 = bitset<64>;
using b_32 = bitset<32>;
using ull = unsigned long long;

//Comperator pair <><><> 1e+25;
//bool comp_2(pair<ss, ll>& a, pair<ss, ll>& b)
    //{return a.s > b.s;}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n;
    if(n > 4 || n == 1)
    {
        m = n - 1;
        while(n > 0)
        {
            cout << n << " ";
            n -= 2;
        }
        while(m > 0)
        {
            cout << m << " ";
            m -= 2;
        }
        cout << endl;
    }
    else if(n == 4) cout << "2 4 1 3 " << endl;
    else cout << "NO SOLUTION" << endl;
    return 0;
}
//Jangan Lupa Endl;