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
    
    ll n, i, sum = 0;
    cin >> n;
    vector<ll> x(n);
    basic_for(i, n)
        cin >> x[i];
    up_for(i, 1, n, 1)
    {
        if(x[i - 1] > x[i]) 
        {
            sum += x[i - 1] - x[i];
            x[i] += x[i - 1] - x[i];
        }
    }
    cout << sum << endl;
    return 0;
}
//Jangan Lupa Endl;