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
    
    // Input 
    vector<vector<bool>> vis (8, vector<bool> (8));
    for(int i = 0; i < 8; i++) {
        string row;
        cin >> row;
        for(int j = 0; j < 8; j++) 
            vis[i][j] = row[j] == '*';
    }

    // 0 1 2 3 4 5 6 7 -> column
    // 0 3 4 5 2 6 7 1 -> Row
    vector<int> qp(8); // Queens Permutation
    iota(all(qp), 0);

    int ans = 0;
    do {
        bool cek = true;
        // Cek Queens placement
        for(int i = 0; i < 8; i++) {
            if(vis[qp[i]][i]) {
                cek = false;
                break;
            }
        } if(!cek) continue;
        
        // Diagonal 1
        vector<bool> dg((8 << 1) - 1);
        for(int i = 0; i < 8; i++) {
            if(dg[qp[i] + i]) {
                cek = false;
                break;
            } dg[qp[i] + i] = true;
        } if(!cek) continue;

        // Diagonal 2
        dg = vector<bool> ((8 << 1) - 1);
        for(int i = 0; i < 8; i++) {
            if(dg[qp[i] - i + 8 - 1]) {
                cek = false;
                break;
            } dg[qp[i] - i + 8 - 1] = true;
        } if(!cek) continue;

        ans += cek;
    } while(next_permutation(all(qp)));
    cout << ans << el;
    return 0;
}

/*
00 01 02 03 04
10 11 12 13 14
20 21 22 23 24 
30 31 32 33 34
40 41 42 43 44
*/

