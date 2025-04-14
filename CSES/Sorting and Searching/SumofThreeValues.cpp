#include <bits/stdc++.h>
using namespace std;

struct f {
    int val, loc;
};

bool comp(f &a, f &b) {   
    return a.val < b.val;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, x, t, i, j;
    cin >> n >> x;

    vector<f> v(n);
    for(i = 0; i < n; i++)
        cin >> v[i].val, v[i].loc = i;
    unordered_map<int, vector<int>> hash;
    sort(v.begin(),v.end(), comp);

    for(i = 0; i < n && x > v[i].val; i++)
        hash[x - v[i].val].push_back(i);
    
    for(i = 0; i < n - 1; i++)
    {
        if(v[i].val >= x) 
            break;
        for(j = i + 1; j < n; j++)
        {
            t = v[i].val + v[j].val;
            if(t >= x) break;
            if(hash.count(t))
            {
                for(auto h : hash[t])
                {
                    if(h != i && h != j)
                    {
                        cout << v[i].loc + 1 <<" "<< v[j].loc + 1 <<" "<< v[h].loc + 1 << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}