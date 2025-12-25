#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void dfs(int x, int y, vector<vector<bool>> &v, vector<vector<bool>> &a) {
    v[x][y] = true;
    vector<pair<int, int>> l = {
        {x - 1, y - 1}, {x - 1, y}, {x - 1, y + 1},
        {x, y - 1}, {x, y + 1},
        {x + 1, y - 1}, {x + 1, y}, {x + 1, y + 1}
    };
    for (auto [p, q] : l) {
        if (p >= 0 and q >= 0 and p < sz(v) and q < sz(v[0]) and !v[p][q] and a[p][q]) {
            dfs(p, q, v, a);
        }
    }
}

void solve() {
    int m, n;
    cin >> m >> n;

    vector<vector<bool>> a(m, vector<bool>(n, false));
    rep(i, 0, m) {
        string s;
        cin >> s;
        rep(j, 0, n) {
            a[i][j] = s[j] == '#';
        }
    }

    int res = 0;
    vector<vector<bool>> v(m, vector<bool>(n, false));
    rep(i, 0, m) {
        rep(j, 0, n) {
            if (!v[i][j] and a[i][j]) {
                dfs(i, j, v, a);
                res++;
                continue;
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
