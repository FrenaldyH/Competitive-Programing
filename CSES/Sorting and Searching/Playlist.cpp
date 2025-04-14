#include <iostream>
#include <map>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, i, j, a, ans;
    cin >> n, i = j = ans = 0;
 
    map<int, int> hash;
    for(; i < n; i++)
    {
        cin >> a;
        if(!hash.count(a))
            hash[a] = i;
        else 
        {
            if(hash[a] >= j)
                j = hash[a] + 1;
            hash[a] = i;
        }
        //cout << j << " " << i << endl;
        if(ans < i - j)
            ans = i - j;
    }
    cout << ans + 1 << endl;
    return 0;
}
