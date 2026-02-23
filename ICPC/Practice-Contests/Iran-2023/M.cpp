#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    int n;
    cin >> n;

    map<string, int> m;
    vi a(n);
    rep(i, 0, n) {
        string s;
        cin >> s;

        if (!m.count(s)) {
            m[s] = sz(m);
        }
        a[i] = 1ll << m[s];
    }

    vector<vector<pii>> v(n), w(n);
    int res = n, k = (1ll << sz(m)) - 1;
    rep(i, 0, n) {
        int x = 0;
        for (int j = i; j >= 0; j--) {
            if ((x | a[j]) != x) {
                x |= a[j];
                v[i].push_back({x, j});
            }
        }
        x = 0;
        rep(j, i, n) {
            if ((x | a[j]) != x) {
                x |= a[j];
                w[i].push_back({x, j});
            }
        }
    }
    
    rep(i, 0, n) {
        rep(j, i + 1, n) {
            int r = sz(w[j]) - 1;
            for (auto [x, s] : v[i]) {
                while (r > 0 and (x | w[j][r - 1].first) == k) {
                    r--;
                }
                if ((x | w[j][r].first) == k) {
                    res = min(res, i - s + 1 + w[j][r].second - j + 1);
                }
            }
        }
    }
    cout << res << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
