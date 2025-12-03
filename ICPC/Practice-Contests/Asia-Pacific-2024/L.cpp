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
const int MOD = 998244353;

bool insert(int x, vector<int> &d) {
    while (x) {
        int i = 63 - __builtin_clzll(x);
        if (!d[i]) {
            d[i] = x;
            return true;
        }
        x ^= d[i];
    }
    return false;
}

void solve() {
	int n;
    cin >> n;

    vector<int> pow2(n), a(n);
    pow2[0] = 1;
    rep(i, 1, n) {
        pow2[i] = pow2[i - 1] * 2 % MOD;
    }

    rep(i, 0, n) {
        cin >> a[i];
    }

    vector<int> d(30, 0);
    int c = 0, res = 1;
    for (int i = n - 1; i > 0; i--) {
        c += insert(a[i] ^ a[0], d);
    }
    rep(i, 0, c) {
        res = res * pow2[n - i - 1] % MOD;
    }
    cout << res << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solve();
}
