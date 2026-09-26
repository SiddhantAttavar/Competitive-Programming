#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
#define debug(...) cout << #__VA_ARGS__ << ": "; print(__VA_ARGS__);
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = (int) 1e9 + 7; //998244353;
inline int mpow(int a, int b) {int x = 1; for (; b; a = a * a % MOD, b >>= 1) {if (b & 1) {x = x * a % MOD;}} return x;};
inline int mdiv(int a, int b) {return a * mpow(b, MOD - 2) % MOD;};

void ins(vi &x, int z) {
	if (z <= 0) {
		return;
	}
	int l = 0, r = sz(x) - 1, u = sz(x);
	while (l <= r) {
		int m = (l + r) / 2;
		if (x[m] <= z) {
			u = m;
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}
	x.insert(x.begin() + u, z);
}

vi get(vector<vi> &dp, vi &v, int i, int l, int r) {
	vi res;
	int j = i;
	do {
		j--;
		vi p = dp[j];
		ins(p, r - max(l, v[j] + 1) + 1);
		res = max(res, p);
	} while (j > 0 and v[j] >= l);
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<pii> a(n), b(m);
		rep(i, 0, n) {
			input(a[i].first, a[i].second);
		}
		rep(i, 0, m)  {
			input(b[i].first, b[i].second);
		}

		vector<pii> x, y;
		int i = 0;
		for (auto [l, r] : a) {
			while (i < m and b[i].first < l) {
				y.push_back(b[i]);
				i++;
			}
			while (i < m and b[i].first <= r) {
				if (b[i].second > r) {
					y.push_back(b[i]);
				}
				i++;
			}
		}
		while (i < m) {
			y.push_back(b[i]);
			i++;
		}

		i = 0;
		for (auto [l, r] : y) {
			while (i < m and a[i].first < l) {
				x.push_back(a[i]);
				i++;
			}
			while (i < n and a[i].first <= r) {
				if (a[i].second > r) {
					x.push_back(a[i]);
				}
				i++;
			}
		}
		while (i < n) {
			x.push_back(a[i]);
			i++;
		}

		x.insert(x.end(), all(y));
		sort(all(x));

		vi v;
		for (auto [l, r] : x) {
			v.push_back(l - 1);
			v.push_back(r);
		}
		v.push_back(0);
		sort(all(v));
		v.erase(unique(all(v)), v.end());

		vector<vi> dp(sz(v));
		dp[0] = {};
		int f = -1, g = -1;
		rep(i, 1, sz(v)) {
			dp[i] = dp[i - 1];
			while (f < sz(x) - 1 and x[f + 1].first <= v[i]) {
				f++;
			}
			while (g < sz(x) - 1 and x[g + 1].second <= v[i]) {
				g++;
			}
			if (g != -1 and x[g].second == v[i]) {
				dp[i] = max(dp[i], get(dp, v, i, x[g].first, min(v[i], x[g].second)));
			}
			else if (f != -1 and x[f].second > v[i]) {
				dp[i] = max(dp[i], get(dp, v, i, x[f].first, min(v[i], x[f].second)));
			}
		}

		print(sz(dp.back()));
		arrprint(dp.back());
	}
}
