#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 30;
vi f(N, 0), g(N, 0);

bool get(int n, int k, vi &res) {
    if (n == 0) {
        return true;
    }
    if (n % 4) {
        return false;
    }
    for (int i = k; i >= 0; i--) {
        int l = f[i], r = i == k ? g[i] - 4 : g[i];
        if (n >= l) {
            int t = min(r, n);
            // cout << i << ' ' << t << endl;
            res.push_back(2ll << i);
            return get(n - t, k - 1, res);
        }
    }
    return false;
}

void solve() {
    int n, k;
    cin >> n >> k;

    while (n--) {
        int h;
        cin >> h;

        vi res;
        if (!get(h, k, res)) {
            cout << -1 << endl;
            continue;
        }
        cout << sz(res);
        for (int i : res) {
            cout << ' ' << i;
        }
        cout << endl;
    }
}

signed main() {
    g[1] = 4;
    rep(i, 2, N) {
        f[i] = (2ll << i) + 2 * f[i - 1];
        g[i] = (2ll << i) + 2 * g[i - 1];
    }
    // rep(i, 0, N) {
    //     cout << (2ll << i) << ": " << f[i] << ' ' << g[i] << endl;
    // }
    // cout << endl;
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
