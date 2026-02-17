#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 1e7;
vi seive(N + 1, true);
vector<array<int, 5>> res(N + 1);
const int MOD = 104206969;

int brute(int n, int k) {
    int res = 0;
    rep(i, 0, 1ll << n) {
        if (__builtin_popcountll(i) != k) {
            continue;
        }
        vi v;
        rep(j, 0, n) {
            if (i >> j & 1) {
                v.push_back(j + 1);
            }
        }
        bool flag = true;
        for (int x : v) {
            for (int y : v) {
                flag &= x == y or seive[abs(x - y)];
            }
        }
        res += flag;
    }
    return res;
}

void solve() {
    int n, k;
    cin >> n >> k;
    
    if (k > 4) {
        cout << 0 << endl;
        // assert(brute(n, k) == 0);
    }
    else {
        cout << res[n][k] % MOD << endl;
        // assert(brute(n, k) == res[n][k]);
    }
}

signed main() {
    seive[0] = false;
    seive[1] = false;
    rep(i, 2, N + 1) {
        if (!seive[i]) {
            continue;
        }
        for (int j = i * i; j <= N; j += i) {
            seive[j] = false;
        }
    }

    int x = 0, y = 0, z = 0;
    res[0] = {1, 0, 0, 0, 0};
    rep(i, 1, N + 1) {
        if (seive[i - 1]) {
            x++;
            y += i >= 6 and seive[i - 3];
        }
        z += i == 8;
        res[i] = {
            res[i - 1][0],
            res[i - 1][1] + 1,
            res[i - 1][2] + x,
            res[i - 1][3] + 2 * y,
            res[i - 1][4] + z
        };
    }

	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    cin >> t;
    while (t--) {
		solve();
	}
}
