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

void op(int x, int i, vi &p, vector<pii> &res) {
    res.push_back({x, i});
    p.erase(find(all(p), x));
    p.insert(p.begin() + i - 1, x);
}

void solve() {
	int n;
    cin >> n;

    vi p(n), q(n);
    rep(i, 0, n) {
        cin >> p[i];
    }
    rep(i, 0, n) {
        cin >> q[i];
    }
    
    vector<pii> res;
    rep(x, 1, n + 1) {
        op(x, x, p, res);
    }
    for (int x = n; x > 0; x--) {
        op(q[x - 1], x, p, res);
    }

    assert(sz(res) <= 10 * n);
    assert(p == q);
    cout << sz(res) << endl;
    for (auto [x, i] : res) {
        cout << x << ' ' << i << endl;
    }
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
}
