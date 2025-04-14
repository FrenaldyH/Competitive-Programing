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

// Global variabel
const int S = 1e3,
minf = INT_MIN, 
pinf = INT_MAX;

// Fren -> Not, Equal, AND, OR
// ASCII 0 = 48, A = 65, a = 97

vector<vector<pair<char, char>>> mat 
    (S + 1, vector<pair<char, char>> (S + 1));
vector<vector<int>> 
    ops (S + 1, vector<int> (S + 1, pinf)),
    dis (S + 1, vector<int> (S + 1, pinf)),
    cek (S + 1, vector<int> (S + 1));
vector<pii> step {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
vector<char> syn {'D', 'R', 'U', 'L'};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    int n, m, i, j, Ay, Ax, by, bx, p, q;
    cin >> n >> m;

    queue<pii> bfs;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            cin >> mat[i][j].fr;
            if(mat[i][j].fr == 'M') {
                bfs.push({i, j});
                dis[i][j] = 0;
            }
            else if(mat[i][j].fr == 'A')
                Ay = i, Ax = j;
            mat[i][j].sc = 'X';
        }
    }

    while(!bfs.empty()) {
        tie(by, bx) = bfs.front();
        bfs.pop(), cek[by][bx] = 1;

        if(ops[by][bx] > dis[by][bx])
            ops[by][bx] = dis[by][bx];
        else continue;

        for(i = 0; i < 4; i++) {
            p = by + step[i].fr;
            q = bx + step[i].sc;

            if(p < 1 || q < 1 || p > n || q > m || mat[p][q].fr != '.')
                continue;
            dis[p][q] = min(dis[p][q], dis[by][bx] + 1);
            bfs.push({p, q});
        }
    }

    //Debug 1
    /* for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            if(ops[i][j] == pinf)
                cout << '#';
            else cout << ops[i][j];
        }
        cout << el;
    } */

    bfs.push({Ay, Ax}), dis[Ay][Ax] = 0;
    mat[Ay][Ax].sc = 'A', Ay = Ax = -1;
    while(!bfs.empty()) {
        tie(by, bx) = bfs.front(), bfs.pop();
        cek[by][bx] = -1;

        if(dis[by][bx] >= ops[by][bx])
            continue;
        if(by == 1 || bx == 1 || by == n || bx == m) {
            Ay = by, Ax = bx; break;
        }

        for(j = 0; j < 4; j++) {
            p = by + step[j].fr;
            q = bx + step[j].sc;

            if(p < 1 || q < 1 || p > n || q > m || mat[p][q].fr != '.' || cek[p][q] == -1) 
                continue;

            dis[p][q] = dis[by][bx] + 1;
            mat[p][q].sc = syn[j];
            bfs.push({p, q});
        }
    }

    //Debug 2
    /* for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            cout << mat[i][j].sc;
        }
        cout << el;
    } */

    unordered_map<char, pii> hash {
        {'R', {0, -1}}, {'L', {0, 1}}, {'U', {1, 0}}, {'D', {-1, 0}}
    };

    //Backtracking
    if(Ay < 0) 
        cout << "NO" << el;
    else {
        cout << "YES" << el;
        stack<char> ans;
        
        // cout << Ay << ' ' << Ax << el;
        by = Ay, bx = Ax;
        while(mat[Ay][Ax].sc != 'A') {
            ans.push(mat[Ay][Ax].sc);
            by += hash[mat[Ay][Ax].sc].fr;
            bx += hash[mat[Ay][Ax].sc].sc;
            Ay = by, Ax = bx;
        }
        cout << ans.size() << el;
        while(!ans.empty()) {
            cout << ans.top(), ans.pop();
        }
        cout << el;
    }

    
    return 0;
}