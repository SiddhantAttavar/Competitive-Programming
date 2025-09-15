#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

const int N = 0;

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<pair<int, int>> v(n);
    rep(i, 0, n)
    {
        char c;
        cin >> c >> v[i].first >> v[i].second;
        if (c == '-')
        {
            v[i].second = -v[i].second;
        }
    }

    vector<int> c(n);
    rep(i, 0, n - 1)
    {
        c[i] = v[i + 1].first - v[i].first;
    }
    c[n - 1] = 0;

    vector<pair<int, int>> p(n);
    p[0] = {v[0].second, 0};
    rep(i, 1, n)
    {
        p[i] = {p[i - 1].first + v[i].second, i};
    }
    sort(p.begin(), p.end());

    int x = 0, y = 0;
    for (auto [i, j] : p)
    {
        x += i * c[j];
        y += c[j];
    }

    vector<pair<int, int>> l(q);
    rep(i, 0, q)
    {
        int b;
        cin >> b;
        l[i] = {b, i};
    }
    sort(l.begin(), l.end());

    bool flag = true;
    while (!p.empty() and p.back().first >= 0)
    {
        int j = p.back().second;
        if (j == n - 1)
        {
            flag = false;
        }
        x -= c[j] * p.back().first;
        y -= c[j];
        p.pop_back();
    }

    vector<int> res(q);
    for (auto [b, i] : l)
    {
        while (!p.empty() and p.back().first + b >= 0)
        {
            int j = p.back().second;
            if (j == n - 1)
            {
                flag = false;
            }
            x -= c[j] * p.back().first;
            y -= c[j];
            p.pop_back();
        }
        if (!flag)
        {
            res[i] = x + y * b;
        }
        else
        {
            res[i] = 1;
        }
    }

    for (int i : res)
    {
        if (i == 1)
        {
            cout << "INFINITY" << endl;
        }
        else
        {
            cout << -i << endl;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("expect.in", "r", stdin);
    // freopen("expect.out", "w", stdout);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
