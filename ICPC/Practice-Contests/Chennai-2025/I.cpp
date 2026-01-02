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

const int N = 2e5;
int low[N + 1], high[N + 1];

int solve(int l, int r, int n, int k, vector<pii> &res) {
    if (l == r) {
        return l;
    }

    int x = r - l + 1;
    rep(j, 1, x) {
        int z = k - min(j, x - j);
        if (z < low[j] + low[x - j] or z > high[j] + high[x - j]) {
            continue;
        }
        int a = max(low[j], z - high[x - j]), b = z - a;
        int p = solve(l, l + j - 1, n, a, res), q = solve(l + j, r, n, b, res);
        res.push_back({p, q});
        return n + sz(res);
    }
}

void solve() {
	int n, k;
    cin >> n >> k;

    if (k < low[n] or k > high[n]) {
        cout << -1 << endl;
        return;
    }

    vector<pii> res;
    solve(1, n, n, k, res);
    for (auto [x, y] : res) {
        cout << x << ' ' << y << endl;
    }
}

signed main() {
    rep(i, 1, N + 1) {
        low[i] = i - 1;
        high[i] = i / 2 + high[i / 2] + high[i - i / 2];
    }
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
}
