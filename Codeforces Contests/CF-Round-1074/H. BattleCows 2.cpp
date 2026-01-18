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
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define pii pair<int, int>
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int sum_until(vi &a, vi &p, int i, int j) {
	if (j <= i) {
		return p[j];
	}
	return p[j] - a[i] + a[j];
}

int check(vi &a, vi &p, vi &q, int i, int j) {
	int u = j, res = 0;
	while (u < sz(a) - 1) {
		int s = sum_until(a, p, i, u) + a[i];
		int v = upper_bound(all(q), s) - q.begin();
		int x = q[v];
		v -= v >= i;
		if (v < sz(a) - 1 and sum_until(a, p, i, v) + a[i] < x) {
			res++;
		}
		u = v + 1;
	}
	return res;
}

int solve(vi &a, vi &p, vi &q, int i, int l, int r, int k) {
	int u = r + 1, o = r;
	while (l <= r) {
		int m = (l + r) / 2;
		if (check(a, p, q, i, m) <= k) {
			u = m;
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}
	return o - u + 1;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		vi a(n), p(n + 1, 0);
		arrput(a);

		vi q(n + 1);
		q[0] = a[0];
		p[1] = a[0];
		rep(i, 1, n) {
			p[i + 1] = p[i] + a[i];
			q[i] = max(q[i - 1], a[i]);
		}
		q[n] = 1e18;

		vi res(n);
		rep(i, 0, n) {
			int l = 0, r = n - 1, u = -1;
			while (l <= r) {
				int m = (l + r) / 2;
				if (sum_until(a, p, i, m) < a[i]) {
					u = m;
					l = m + 1;
				}
				else {
					r = m - 1;
				}
			}

			res[i] = solve(a, p, q, i, 0, u, k) + solve(a, p, q, i, u + 1, n - 1, k - 1);
		}
		arrprint(res);
		cout.flush();
	}
}
