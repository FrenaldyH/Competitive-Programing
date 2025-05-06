#include <bits/stdc++.h>
using namespace std;

//Shortcut
#define fp(i, l, r)     for(i = l; i < r; i++)
#define ms(x, y)        memset(x, y, sizeof(x))
#define all(x)          x.begin(), x.end()
#define sc              second
#define fr              first
#define el              '\n'

using dd                = double;
using ll                = long long;
using ull               = unsigned long long;
using pii               = pair<int, int>;
using pll               = pair<ll, ll>;

// Global variabel
const int S = 5e5,
minf = INT_MIN, 
pinf = INT_MAX;
ll nums[S + 1];

// Fren -> Not, Equal, AND, OR
// ASCII 0 = 48, A = 65, a = 97

/**
 *      Solved: 06.05.2005
 *      Sumber: https://codeforces.com/contest/616/problem/D
**/

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    int n, k, i, l, r, lmax, rmax, maxsub;
    map<ll, int> mp;

    cin >> n >> k;
    fp(i, 1, n + 1) 
        cin >> nums[i];

    l = r = 1;
    maxsub = -1;
    fp(r, 1, n + 1) {
        mp[nums[r]]++;
        while(mp.size() > k && l < r) {
            mp[nums[l]]--;
            if(mp[nums[l]] <= 0)
                mp.erase(mp.find(nums[l]));
            l++;
        }
        if(maxsub < r - l) {
            maxsub = r - l;
            lmax = l;
            rmax = r;
        }
    }
    cout << lmax << ' ' << rmax << el;
    return 0;
}
