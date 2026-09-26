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

void push(int l, int r, int c, vi &seg, vi &lazy) {
	seg[c] = min(seg[c], lazy[c]);
	if (l != r) {
		lazy[2 * c] = min(lazy[2 * c], lazy[c]);
		lazy[2 * c + 1] = min(lazy[2 * c + 1], lazy[c]);
	}
	lazy[c] = 1e18;
}

int query(int l, int r, int s, int e, int c, vi &seg, vi &lazy) {
	push(s, e, c, seg, lazy);
	if (l > e or r < s) {
		return -1;
	}
	if (l <= s and e <= r) {
		return seg[c];
	}
	int m = (s + e) / 2;
	return max(query(l, r, s, m, 2 * c, seg, lazy), query(l, r, m + 1, e, 2 * c + 1, seg, lazy));
}

void upd(int l, int r, int x, int s, int e, int c, vi &seg, vi &lazy) {
	push(s, e, c, seg, lazy);
	if (l > e or r < s) {
		return;
	}
	if (l <= s and e <= r) {
		lazy[c] = x;
		push(s, e, c, seg, lazy);
		return;
	}
	int m = (s + e) / 2;
	upd(l, r, x, s, m, 2 * c, seg, lazy);
	upd(l, r, x, m + 1, e, 2 * c + 1, seg, lazy);
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vi a(n);
		arrput(a);

		vi s(2 * n + 1, true), l;
		vector<vi> d(2 * n + 1);
		rep(i, 2, 2 * n + 1) {
			for (int j = i; j <= 2 * n; j += i) {
				d[i].push_back(j);
			}
			if (!s[i]) {
				continue;
			}
			for (int j = i; j <= 2 * n; j += i) {
				s[j] = false;
			}
			for (int j = i; j <= 2 * n; j *= i) {
				l.push_back(j);
			}
		}
		sort(all(l));

		vector<vi> f(2 * n + 1);
		rep(i, 0, n) {
			f[a[i]].push_back(i);
		}

		vi seg(4 * n, n), lazy(4 * n, 1e18), res;
		rep(i, 0, n) {
			upd(i, i, i, 0, n - 1, 1, seg, lazy);
		}
		for (int x : l) {
			vi v;
			for (int y = x; y <= 2 * n; y += x) {
				v.insert(v.end(), all(f[y]));
			}
			sort(all(v));
			v.push_back(n);

			int j = -1;
			bool flag = false;
			for (int i : v) {
				if (j + 1 > i - 1) {
					j = i;
					continue;
				}
				if (query(j + 1, i - 1, 0, n - 1, 1, seg, lazy) > j) {
					flag = true;
				}
				upd(j + 1, i - 1, j, 0, n - 1, 1, seg, lazy);
				j = i;
			}
			if (flag) {
				res.push_back(x);
			}
		}
		print(sz(res));
		arrprint(res);
	}
}
