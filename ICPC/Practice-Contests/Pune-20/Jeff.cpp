#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define vi vector<int>
#define all(v) begin(v), end(v)

void solve()
{
    int n, j;
    cin >> n >> j;
    j--;

    string s;
    cin >> s;

    int x = 0;
    rep(i, j, n) {
        x += s[i] == '#';
    }

    if (x > j) {
        cout << "JEFF\n";
    }
    else {
        cout << "JAY\n";
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int tt;
    cin >> tt;
    while (tt--)
    {
        solve();
    }
}
