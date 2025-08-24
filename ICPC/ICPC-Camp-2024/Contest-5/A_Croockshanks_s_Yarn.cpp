#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

bool check(vector<pair<int, int>> &res, int n, int k) {
    set<pair<int, int>> s(res.begin(), res.end());
    if (s.size() < n) {
        return false;
    }
    vector<vector<int>> r(k), c(k);
    rep(i, 0, n) {
        r[res[i].first - 1].push_back(i + 1);
        c[res[i].second - 1].push_back(i + 1);
    }
    vector<int> x(k, 0), y(k, 0);
    rep(i, 0, k) {
        if (r[i].size() < 2) {
            return false;
        }
        for (int j : r[i]) {
            x[i] = __gcd(x[i], j);
        }
        if (c[i].size() < 2) {
            return false;
        }
        for (int j : c[i]) {
            y[i] = __gcd(x[i], j);
        }
        if (x[i] != y[i]) {
            return false;
        }
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k, n;
    cin >> k >> n;

    vector<pair<int, int>> res(n);
    res[0] = {k, 1};
    rep(i, 2, 2 * k + 1) {
        res[i - 1] = {i / 2, (i + 1) / 2};
    }
    int u = 2 * k + 1;
    rep(x, 1, k + 1) {
        rep(y, 1, k + 1) {
            if (x != y and x != y - 1 and (x != k or y != 1)) {
                res[u - 1] = {x, y};
                u++;
            }
            if (u == n + 1) {
                break;
            }
        }
        if (u == n + 1) {
            break;
        }
    }
    for (auto [x, y] : res) {
        cout << x << ' ' << y << endl;
    }
    // assert(check(res, n, k));
}
