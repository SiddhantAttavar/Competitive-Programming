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

bool check(vector<pair<int, int>> &res, vector<int> &a, int m) {
	vector<int> h = a;
	int n = h.size();
	vector<bool> v(n, false);
	for (auto [x, y] : res) {
		if (v[x] or h[x] <= 0 or h[y] <= 0) {
			return false;
		}
		h[x] -= a[y];
		h[y] -= a[x];
		v[x] = true;
	}
	int b = 0, c = 0;
	rep(i, 0, n) {
		m -= h[i] > 0;
		b += h[i] > 0;
		c += h[i] > 0 and !v[i];
	}
	if (b >= 2 and c >= 1) {
		return false;
	}
	return m == 0;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<int> a(n);
		arrput(a);

		int o = m;
		vector<int> v(n);
		iota(v.begin(), v.end(), 0);
		sort(v.begin(), v.end(), [&](int i, int j) {
			return a[i] < a[j];
		});

		vector<pair<int, int>> res;
		bool flag = true;
		while (m > 1) {
			if (n < 2) {
				flag = false;
				break;
			}
			int p = v[n - 1], q = v[n - 2];
			res.push_back({p, q});
			n -= 2;
			m--;
		}

		if (!flag) {
			print(-1);
			continue;
		}


		if (m == 0) {
			int u = n - 2, x = 0;
			while (u >= 0 and x < a[v[n - 1]]) {
				x += a[v[u]];
				u--;
			}
			u++;

			if (x < a[v[n - 1]]) {
				print(-1);
				continue;
			}

			rep(i, 0, u) {
				res.push_back({v[i + 1], v[i]});
			}
			res.push_back({v[n - 1], v[u]});
			rep(i, u + 1, n - 1) {
				res.push_back({v[i], v[n - 1]});
			}
		}
		else {
			if (n < 2) {
				print(-1);
				continue;
			}

			rep(i, 0, n - 1) {
				res.push_back({v[i + 1], v[i]});
			}
		}

		print(res.size());
		for (auto [x, y] : res) {
			print(x + 1, y + 1);
		}
		cout.flush();
		assert(check(res, a, o));
	}
}
