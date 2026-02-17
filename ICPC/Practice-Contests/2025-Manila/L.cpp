#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MOD = 1006903069;

void solve() {
    int n;
    cin >> n;

    int ka;
    cin >> ka;
    vector<vector<pii>> a(n);
    while (ka--) {
        int i, j, x;
        cin >> i >> j >> x;

        a[i - 1].push_back({j - 1, x});
    }

    int kb;
    cin >> kb;
    vector<vector<pii>> b(n);
    while (kb--) {
        int i, j, x;
        cin >> i >> j >> x;

        b[j - 1].push_back({i - 1, x});
    }

    int res = 0;
    rep(i, 0, n) {
        sort(all(a[i]));
        sort(all(b[i]));

        int l = 0;
        rep(j, 0, sz(a[i])) {
            while (l < sz(b[i]) and b[i][l].first < a[i][j].first) {
                l++;
            }
            if (l < sz(b[i]) and b[i][l].first == a[i][j].first) {
                res = (res + a[i][j].second * b[i][l].second) % MOD;
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
