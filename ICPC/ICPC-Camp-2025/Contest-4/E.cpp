#include <bits/stdc++.h>
using namespace std;


void solve()
{
    long long l = 0, r = 0, flag = 1, ans = 0;
    cin >> l >> r;
    vector<int> l_bin(63, 0), r_bin(63, 0);

    if(l == 0)
    {
        cout << l << '\n';
        return;
    }
    

    for(int i = 0; i <= 62; i++)
    {
        if(l % 2 == 1)
        {
            l_bin[i] = 1;
        }
        l /= 2;
    }

    for(int i = 0; i <= 62; i++)
    {
        if(r % 2 == 1)
        {
            r_bin[i] = 1;
        }
        r /= 2;
    }

    for(int i = 62; i >= 0; i--)
    {
        if(l_bin[i] == 0 && r_bin[i] == 1)
        {
            flag = 0;
        }
        if(!flag && l_bin[i] == 1)
        {
            ans += (1LL << i);
        }
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
}
