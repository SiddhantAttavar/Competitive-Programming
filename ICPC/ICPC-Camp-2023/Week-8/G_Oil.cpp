#include <bits/stdc++.h>
using namespace std;
#define int long long

int solve(int x, int x_prime, int y, vector<pair<int, pair<int, int>>> &v) {
    vector<pair<int, pair<int, int>>> w;
    for (pair<int, pair<int, int>> p : v) {
        if (p.first == y) {
            continue;
        }

        if (p.first > y) {
            w.push_back(p);
        }
        else {
            w.push_back({
                2 * y - p.first,
                {
                    2 * x - p.second.second,
                    2 * x - p.second.first
                }
            });
        }
        
        w.push_back({
            w.back().first,
            {w.back().second.second, w.back().second.first}
        });
    }

    sort(w.begin(), w.end(), [&](pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
        if ((a.second.first > x) != (b.second.first > x)) {
            return a.second.first <= x;
        }
        if ((a.first - y) * (b.second.first - x) == (b.first - y) * (a.second.first - x)) {
            return a.second.first - a.second.second < b.second.first - b.second.second;
        }
        if (a.second.first == x or b.second.first == x) {
            return b.second.first == x;
        }
        return (a.first - y) * (b.second.first - x) > (b.first - y) * (a.second.first - x);
    });

    int c = abs(x - x_prime), res = abs(x - x_prime);
    // cerr << c << endl;
    for (pair<int, pair<int, int>> p : w) {
        c += p.second.second - p.second.first;
        // cerr << c << endl;
        res = max(res, c);
    }
    // cerr << x << " " << y << " " << res << endl;
    // for(auto [y, p] : w) {
    //     cerr << y << " : " << p.first << " " << p.second << endl;
    // }
    // cerr << " ----- " << endl;
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, pair<int, int>>> v;
    for (int i = 0; i < n; i++) {
        int x0, x1, y;
        cin >> x0 >> x1 >> y;
        v.push_back({y, {x0, x1}});
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        res = max({
            res,
            solve(v[i].second.first, v[i].second.second, v[i].first, v),
            solve(v[i].second.second, v[i].second.first, v[i].first, v)
        });
    }
    cout << res << endl;
}
