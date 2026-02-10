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

int check(int l, int r, int m, string &s, vi &p, vi &q, vector<vi> &x) {
    int d = -(p[r + 1] - p[l]) - m, n = sz(p) - 1;
    if (d < 0) {
        return m;
    }
    
    int i = max(l, (int) (lower_bound(all(q), q[l] + m) - q.begin()));
    int u = p[i] + n + 1;
    int j = lower_bound(all(x[u]), i + 1) - x[u].begin();
    if (j == sz(x[u]) or x[u][j] - 1 > r) {
        return -1;
    }

    if (2 * (q[r + 1] - q[x[u][j] - 1]) > d) {
        return m + d / 2 + 1;
    }
    return -1;
}

void solve() {
	int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vi p(n + 1, 0), q(n + 1, 0), t(n + 1, n);
    rep(i, 0, n) {
        p[i + 1] = p[i] + (s[i] == 'A' ? 1 : -1);
        q[i + 1] = q[i] + (s[i] == 'B');
    }
    for (int i = n - 1; i >= 0; i--) {
        t[i] = s[i] == 'A' ? i : t[i + 1];
    }

    vector<vi> x(2 * n + 2);
    rep(i, 0, n) {
        x[p[i] + n].push_back(i);
    }

    while (k--) {
        int l, r;
        cin >> l >> r;

        l--;
        r--;

        if (p[r + 1] > p[l]) {
            cout << 0 << endl;
            continue;
        }

        if (t[l] > r) {
            cout << -1 << endl;
            continue;
        }
        
        int a = 0, b = t[l] - l, res = r - l + 1;
        while (a <= b) {
            int m = (a + b) / 2;
            int z = check(l, r, m, s, p, q, x);
            if (z == -1) {
                a = m + 1;
            }
            else {
                res = z;
                b = m - 1;
            }
        }
        cout << res << endl;
    }
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
}
