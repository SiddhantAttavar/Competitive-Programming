#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool debug = false;
vi f;
int K = 1000;

int query(int c, int r) {
	assert(K--);
	if (debug) {
		assert(1 <= c and c <= sz(f) and 1 <= r and r <= sz(f));
		while (c--) {
			r = f[r];
		}
		return r;
	}
	cout << "? " << c << ' ' << r << endl;
	cout.flush();
	int x;
	cin >> x;
	return x;
}

void solve() {
    int n;
	cin >> n;

	int k = 500;
	if (debug) {
		f.resize(n + 1);
		rep(i, 0, n) {
			cin >> f[i + 1];
		}
	}

	vi v(n + 1, -1);
	int u = query(n, 1), o = u, l = -1;
	v[u] = 0;
	rep(i, 0, k - 1) {
		u = query(1, u);
		if (v[u] != -1) {
			l = i + 1 - v[u];
			break;
		}
		v[u] = i + 1;
	}
	u = o;
	rep(i, 0, k) {
		if (l != -1) {
			break;
		}
		u = query(k, u);
		if (v[u] != -1) {
			l = (i + 1) * k - v[u];
			break;
		}
	}
	assert(l != -1);
	u = query(l - o % l, o);
	cout << "! " << o << ' ' << u << endl;
	cout.flush();
	if (debug) {
		assert(query(o, u) == o);
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
