#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)((x).size()))
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

array<int, 4> merge(array<int, 4> a, array<int, 4> b) {
    if (a[1] < b[1]) {
        swap(a, b);
    }
    int hdiff = a[1] - b[1];
    a = {a[0] + hdiff, b[1], a[2] - hdiff, a[3] + hdiff};

    if (a[2] > b[2]) {
        swap(a, b);
    }
    if (a[3] >= b[2]) {
        return {
            a[0] + b[0] - 1,
            b[1],
            b[2],
            a[3]
        };
    }

    int l = a[3], r = b[2];
    int x = max(0ll, r - l - 2);
    int h = (x + 1) / 2 + 1;

    if (b[1] - h < 0) {
        return {
            a[0] + b[0] + 2 * b[1],
            0,
            a[2],
            b[3]
        };
    }

    return {
        a[0] + b[0] + 2 * h - 1,
        b[1] - h,
        r - h,
        l + h
    };
}

void solve() {
	int n, h;
    cin >> n >> h;

    vector<int> x(n);
    rep(i, 0, n) {
        cin >> x[i];
    }

    const int inf = 1e18;
    vector<vector<array<int, 4>>> dp(n, vector<array<int, 4>>(n, {inf, inf, inf, inf}));
    rep(i, 0, n) {
        dp[i][i] = {0, h, x[i], x[i]};
    }
    rep(l, 2, n + 1) {
        rep(i, 0, n - l + 1) {
            int j = i + l - 1;
            rep(k, i, j) {
                dp[i][j] = min(dp[i][j], merge(dp[i][k], dp[k + 1][j]));
            }
        }
    }
    // rep(i, 0, n) {
    //     rep(j, i, n) {
    //         cout << dp[i][j][0] << ' ';
    //     }
    //     cout << endl;
    // }
    cout << dp[0][n - 1][0] + dp[0][n - 1][1] << endl;
    // cout << dp[0][n - 1][0] << ' ' << dp[0][n - 1][1] << ' ' << dp[0][n - 1][2] << ' ' << dp[0][n - 1][3] << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solve();
}
