#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    int n;
	cin >> n;

	map<string, int> p;
	vector<string> a;
	vector<pii> v;
	rep(i, 0, n) {
		string s;
		cin >> s;

		int x, y;
		cin >> x >> y;
		p[s] = sz(v);
		v.push_back({x, y});
		a.push_back(s);
	}

	int m;
	cin >> m;
	vi x(m);
	rep(i, 0, m) {
		string s;
		cin >> s;
		if (!p.count(s)) {
			p[s] = sz(v);
			v.push_back({0, 0});
			a.push_back(s);
		}
		x[i] = p[s];
	}
	
	int q, k;
	cin >> q >> k;
	while (q--) {
		int l;
		cin >> l;
		vector<string> b(l);
		vi c(l), d(l);
		rep(i, 0, l) {
			cin >> b[i];
			c[i] = p.count(b[i]) ? p[b[i]] : -1;
		}
		
		string res = "*";
		for (int i = k; i > 0; i--) {
			vi t;
			rep(j, 0, m - i) {
				bool flag = true;
				rep(u, 0, i) {
					if (c[l - i + u] != x[j + u]) {
						flag = false;
						break;
					}
				}
				if (flag) {
					t.push_back(x[j + i]);
				}
			}
			
			if (t.empty()) {
				continue;
			}
			
			int u = -1, z = -1e18;
			rep(f, 0, sz(v)) {
				int y = 0;
				for (int g : t) {
					y += v[f].first * v[g].first + v[f].second * v[g].second;
				}
				if (y > z) {
					z = y;
					u = f;
				}
			}
			res = a[u];
			break;
		}
		for (string s : b) {
			cout << s << ' ';
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
