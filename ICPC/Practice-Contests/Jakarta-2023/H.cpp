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
const int N = 1e6;
vi fact(N + 1, 1), inv_fact(N + 1, 1);

int mpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int mdiv(int a, int b) {
    return a * mpow(b, MOD - 2) % MOD;
}

void solve() {
    rep(i, 1, N + 1) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    inv_fact[N] = mdiv(1, fact[N]);
    for (int i = N - 1; i >= 0; i--) {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
    }

	int n, m;
    cin >> n >> m;

    string a, b;
    cin >> a >> b;

    vi f(26, 0), g(26, 0);
    for (char c : a) {
        f[c - 'A']++;
    }
    for (char c : b) {
        g[c - 'A']++;
    }

    vi p(26, 0);
    p[0] = f[0];
    rep(i, 1, 26) {
        p[i] = p[i - 1] + f[i];
    }
    // for (int i : p) cout << i << ' ';
    // cout << endl;
    
    vi dp(n + 1, 0);
    dp[0] = 1;
    rep(i, 0, p[0] + 1) {
        if (i + 1 <= g[0]) {
            dp[i + 1] = inv_fact[i + 1];
        }
    }
    // for (int i : dp) cout << i << ' ';
    // cout << endl;
    // cout.flush();
    rep(c, 1, 26) {
        int z = 0, l = 0;
        rep(i, 0, p[c - 1] + 1) {
            int x = p[c - 1] - i;
            z = (z + dp[i] * inv_fact[x]) % MOD;
        }
        
        vi ndp(n + 1, 0);
        rep(i, p[c - 1], p[c] + 1) {
            while (l <= p[c - 1] and i - l > g[c]) {
                int x = p[c - 1] - l;
                z = (z - (dp[l] * inv_fact[x] % MOD) + MOD) % MOD;
                l++;
            }
            int y = i - p[c - 1];
            ndp[i] = z * inv_fact[y] % MOD;
        }
        dp = ndp;
        // for (int i : dp) cout << i << ' ';
        // cout << endl;
        // cout.flush();
    }
    cout << (dp[n] * fact[n]) % MOD << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solve();
}
