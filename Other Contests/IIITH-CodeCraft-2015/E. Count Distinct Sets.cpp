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
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

void left(int l, int r, int n, int d, int k, vector<int> &a) {
	if (r <= n) {
		a[d] = (1ll << (k - d + 1)) - 1;
	}
	if (l == r) {
		return;
	}
	int m = l + (r - l) / 2;
	left(l, m, n, d + 1, k, a);
}

void right(int l, int r, int n, int d, int k, vector<int> &c) {
	if (l == r) {
		return;
	}
	if (l > n) {
		c[d] = (1ll << (k - d)) - 1;
	}
	int m = l + (r - l) / 2;
	right(m + 1, r, n, d + 1, k, c);
}

void solve(int l, int r, int n, int d, int k, vector<int> &b) {
	if (l <= n and n < r) {
		b[d] = (1ll << (k - d + 1)) - 1 - (r - n);
	}
	if (l == r or l > n or r < n) {
		return;
	}
	int m = l + (r - l) / 2;
	solve(l, m, n, d + 1, k, b);
	solve(m + 1, r, n, d + 1, k, b);
}

int brute(int n) {
	vector<int> v(n);
	rep(i, 0, n) {
		v[i] = i;
	}
	vector<set<int>> a(n);
	do {
		bool flag = true;
		rep(i, 1, n) {
			if (v[i] < v[(i - 1) / 2]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			rep(i, 0, n) {
				a[v[i]].insert(i);
			}
		}
	} while (next_permutation(v.begin(), v.end()));
	set<set<int>> b(a.begin(), a.end());
	return b.size();
}

int brute2(int l, int r, int n, int d, vector<set<int>> &h) {
	if (l == r) {
		if (l <= n) {
			h[d].insert(1);
		}
		return l <= n;
	}
	int m = l + (r - l) / 2;
	int s = brute2(l, m, n, d + 1, h) + brute2(m + 1, r, n, d + 1, h) + 1;
	h[d].insert(s);
	return s;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		int k = 1, x = 0;
		while (2 * k <= n) {
			k *= 2;
			x++;
		}

		vector<int> a(60, -1), b(60, -1), c(60, -1);
		left(k, 2 * k - 1, n, 0, x, a);
		right(k, 2 * k - 1, n, 0, x, c);
		solve(k, 2 * k - 1, n, 0, x, b);
		vector<pair<int, bool>> v;
		rep(i, 0, 60) {
			if (a[i] != -1) {
				// print(i + 1, n - a[i] + 1);
				v.push_back({i + 1, false});
				v.push_back({n - a[i] + 2, true});
			}
			if (b[i] != -1) {
				// print(i + 1, n - b[i] + 1);
				v.push_back({i + 1, false});
				v.push_back({n - b[i] + 2, true});
			}
			if (c[i] != -1) {
				// print(i + 1, n - c[i] + 1);
				v.push_back({i + 1, false});
				v.push_back({n - c[i] + 2, true});
			}
		}
		sort(v.begin(), v.end());
		int res = 0, z = 1;
		rep(i, 1, v.size()) {
			if (v[i].first != v[i - 1].first) {
				// print(v[i - 1].first);
				res += z > 0;
			}
			if (v[i].second) {
				z--;
			}
			else {
				z++;
			}
		}
		print(res);

		// print(res, brute(n));
		// cout.flush();
		// assert(res == brute(n));

		// vector<set<int>> h(60);
		// brute2(k, 2 * k - 1, n, 0, h);
		// int res = 0;
		// rep(i, 0, 60) {
		// 	res += h[i].size();
		// }
		// print(accumulate(a.begin(), a.end(), 0) + accumulate(b.begin(), b.end(), 0) + accumulate(c.begin(), c.end(), 0), res);
		// cout.flush();
		// assert(accumulate(a.begin(), a.end(), 0) + accumulate(b.begin(), b.end(), 0) + accumulate(c.begin(), c.end(), 0) == res);
	}
}
