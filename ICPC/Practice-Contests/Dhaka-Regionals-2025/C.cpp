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

const int N = 50 * 50 * 50;

int cmb(int x, int y, int z) {
    return 50 * 50 * z + 50 * y + x;
}

int dfs(int i, int j, int k, vector<bool> &a, vector<bool> &v, vector<array<int, 3>> &l) {
    vector<array<int, 3>> n = {
        {i - 1, j, k}, {i + 1, j, k},
        {i, j - 1, k}, {i, j + 1, k},
        {i, j, k - 1}, {i, j, k + 1}
    };
    l.push_back({i, j, k});
    v[cmb(i, j, k)] = true;
    int res = 1;
    for (auto [x, y, z] : n) {
        if (min({x, y, z}) >= 0 and max({x, y, z}) < 50 and !v[cmb(x, y, z)] and !a[cmb(x, y, z)]) {
            res += dfs(x, y, z, a, v, l);
        }
    }
    return res;
}

void solve() {
	int x, y, z;
    cin >> x >> y >> z;

    vector<bool> a(N, true);
    rep(i, 0, z) {
        rep(j, 0, x) {
            string s;
            cin >> s;
            rep(k, 0, y) {
                a[cmb(j, k, i)] = s[k] == '#';
            }
        }
    }

    vector<bool> v(N, false);

    vector<int> comp(N, 0);
    vector<int> siz = {0};
    int c = 0;
    rep(i, 0, x) {
        rep(j, 0, y) {
            rep(k, 0, z) {
                if (!a[cmb(i, j, k)] and !v[cmb(i, j, k)]) {
                    vector<array<int, 3>> l;
                    siz.push_back(dfs(i, j, k, a, v, l));
                    c++;
                    for (auto [p, q, r] : l) {
                        comp[cmb(p, q, r)] = c;
                    }
                }
            }
        }
    }

    int res = 0;
    rep(i, 0, x) {
        rep(j, 0, y) {
            int c = 0;
            set<int> s;
            rep(k, 0, z) {
                if (!a[cmb(i, j, k)] and !s.count(comp[cmb(i, j, k)])) {
                    s.insert(comp[cmb(i, j, k)]);
                    c += siz[comp[cmb(i, j, k)]];
                }
            }
            res = max(res, c);
        }
    }

    cout << res << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
}
