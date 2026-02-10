#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 2e6;
int a[N + 1], c[N + 1];
vi d[N + 1];

int get(int x, int n) {
    int res = 0;
    rep(i, 0, (n + 1) / 2) {
        if (a[i] > x) {
            int k = a[i] / (x + 1) + 1;
            res += c[k];
        }
    }
    return res;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    fill(c, c + 2 * m + 1, 1e18);
    rep(i, 0, n) {
        cin >> a[i];
    }
    sort(a, a + n);
    rep(i, 1, m + 1) {
        cin >> c[i];
    }
    m *= 2;

    for (int i = m - 1; i >= 0; i--) {
        c[i] = min(c[i], c[i + 1]);
    }
    rep(i, 1, m + 1) {
        for (int j : d[i]) {
            c[i] = min(c[i], c[j] + c[i / j]);
        }
    }
    for (int i = m - 1; i >= 0; i--) {
        c[i] = min(c[i], c[i + 1]);
    }

    int l = 0, r = m - 1, res = m;
    while (l <= r) {
        int x = (l + r) / 2;
        if (get(x, n) <= k) {
            res = x;
            r = x - 1;
        }
        else {
            l = x + 1;
        }
    }
    cout << res << endl;
}

signed main() {
    rep(i, 1, N + 1) {
        for (int j = 2 * i; j * j <= N; j += i) {
            d[j].push_back(i);
        }
    }
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    cin >> t;
    while (t--) {
		solve();
	}
}
