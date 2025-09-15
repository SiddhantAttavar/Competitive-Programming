#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 0;

void solve()
{
    string s;
    cin >> s;

    int n = s.size();

    vector<long double> dp(n + 1, 0), t1(n + 1, 0), t2(n + 1, 0);
    vector<int> p(n + 1, 0), q(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        int l = n - i;
        p[i] = p[i + 1] + (s[i] == 'C');
        q[i] = q[i + 1] + (s[i] == 'W');
        t1[i] = t1[i + 1] + dp[i + 1] - p[i + 1];
        t2[i] = t2[i + 1] + dp[i + 1] - q[i + 1];
        if (s[i] == 'W')
        {
            dp[i] = (t1[i]) / l + p[i];
        }
        else
        {
            dp[i] = (t2[i]) / l + q[i];
        }
    }
    cout << fixed << setprecision(15);
    cout << dp[0] << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("foreign.in", "r", stdin);
    // freopen("foreign.out", "w", stdout);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
