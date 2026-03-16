#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<class T> struct RMQ {
    vector<vector<T>> jmp;
    RMQ(const vector<T> &V) : jmp(1, V) {
        for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, k++) {
            jmp.emplace_back(sz(V) - pw * 2 + 1);
            rep(j, 0, sz(jmp[k])) {
                jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
            }
        }
    }
    T query(int a, int b) {
        b++;
        assert(a < b);
        int dep = 31 - __builtin_clz(b - a);
        return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<vi> p(n + 1, vi(26, 0)), v(26);
    rep(i, 0, n) {
        p[i + 1] = p[i];
        p[i + 1][s[i] - 'a']++;
        v[s[i] - 'a'].push_back(i);
    }
    
    vector<vi> x(26);
    rep(i, 0, n) {
        int u = s[i] - 'a';
        if (i == v[u].back()) {
            continue;
        }
        int j = v[u][p[i + 1][u]];
        int c = 0;
        while (c < 26 and j + c < n and i + c < j and s[i + c] == s[j + c]) {
            c++;
        }
        x[u].push_back(c);
    }
    vector<RMQ<int>> y;
    rep(i, 0, 26) {
        y.push_back(RMQ<int>(x[i]));
    }

    while (q--) {
        int l, r;
        cin >> l >> r;

        l--;
        r--;

        int k = 0;
        rep(i, 0, 26) {
            k = max(k, p[r + 1][i] - p[l][i]);
        }

        if (k == 1) {
            cout << r - l + 1 << endl;
            continue;
        }

        int res = 0;
        rep(i, 0, 26) {
            if (k == p[r + 1][i] - p[l][i]) {
                int a = p[l][i], b = p[r + 1][i] - 1;
                res = max(res, min(y[i].query(a, b - 1), r - v[i][b] + 1));
            }
        }
        cout << res << endl;
    }
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
