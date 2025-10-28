#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define ll long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((ll)((x).size()))
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    int n;
    cin >> n;

    int x0, y0;
    cin >> x0 >> y0;

    map<pair<int, int>, vector<int>> m;
    vector<int> x(n), y(n);
    rep(i, 1, n) {
        cin >> x[i] >> y[i];
        x[i] -= x0;
        y[i] -= y0;

        int g = __gcd(abs(x[i]), abs(y[i]));
        m[{y[i] / g, x[i] / g}].push_back(i);
    }

    vector<int> res = {0};
    for (auto [k, v] : m) {
        vector<pair<int, int>> a;
        for (int i : v) {
            if (y[i] == 0) {
                a.push_back({x[i], i});
            }
            else {
                a.push_back({y[i], i});
            }
        }
        sort(a.begin(), a.end());
        if (a[0].first < 0) {
            reverse(a.begin(), a.end());
        }
        for (auto [_, i] : a) {
            res.push_back(i);
        }
        a.pop_back();
        reverse(a.begin(), a.end());
        for (auto [_, i] : a) {
            res.push_back(i);
        }
        res.push_back(0);
    }

    cout << res.size() << endl;
    for (int i : res) {
        cout << i + 1 << ' ';
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1; while (t--) {
        solve();
    }
}
