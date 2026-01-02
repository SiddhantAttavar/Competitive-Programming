#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

const int N = 1e5, K = 30;
ld p[N], q[N], probs[N];
ld powp[N][K + 1], powq[N][K + 1], pow2p[N][K + 1];

void get_expected_probs(int w, int l, int n) {
    rep(i, 0, n) {
        probs[i] = powp[i][w] * powq[i][l];
    }
}

ld expected_profit(int k, ld z, int n) {
    ld res = 0;
    rep(i, 0, n) {
        res += probs[i] * pow2p[i][k];
    }
    return (res - z) / z;
}

void solve() {
    int n, k;
    cin >> n >> k;

    rep(i, 0, n) {
        cin >> p[i];
        p[i] /= 100.0L;
        q[i] = 1.0L - p[i];
    }

    rep(i, 0, n) {
        powp[i][0] = 1;
        powq[i][0] = 1;
        pow2p[i][0] = 1;
        rep(j, 0, k) {
            powp[i][j + 1] = powp[i][j] * p[i];
            powq[i][j + 1] = powq[i][j] * q[i];
            pow2p[i][j + 1] = pow2p[i][j] * 2 * p[i];
        }
    }

    vector<vector<ld>> dp(k + 1, vector<ld>(k + 1, 0));
    for (int w = k - 1; w >= 0; w--) {
        for (int l = k - 1; l >= 0; l--) {
            if (w + l > k) {
                continue;
            }
            get_expected_probs(w, l, n);
            ld expected_prob = 0, z = accumulate(probs, probs + n, 0.0L);
            rep(i, 0, n) {
                expected_prob += probs[i] * p[i];
            }
            dp[w][l] = max({0.0L,
                expected_profit(k - w - l, z, n),
                (expected_prob * dp[w + 1][l] + (z - expected_prob) * dp[w][l + 1]) / z
            });
        }
    }
    cout << fixed << setprecision(20) << (dp[0][0] * 1000.0L) << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
