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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    deque<ll> t;
    while(n != 1)
    {
        t.push_back(n);
        if(n % 2 == 0) n /= 2;
        else n = (n*3) + 1;
    }
    t.emplace_back(1);
    while(!t.empty())
    {
        cout << t.front() << " ";
        t.pop_front();
    }
    cout << endl;
    return 0;
}