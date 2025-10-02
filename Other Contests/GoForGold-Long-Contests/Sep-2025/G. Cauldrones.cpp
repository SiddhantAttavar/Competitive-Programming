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

bool check(int m, int x, vector<int> &t, vector<int> &c) {
	rep(i, 0, t.size()) {
		x -= (m / t[i]) * c[i];
		if (x <= 0) {
			return true;
		}
	}
	return false;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, x;
		input(n, x);

		vector<int> t(n), c(n);
		rep(i, 0, n) {
			input(t[i], c[i]);
		}

		int l = 0, r = 1e18, res = 1e18;
		while (l <= r) {
			int m = (l + r) / 2;
			if (check(m, x, t, c)) {
				res = m;
				r = m - 1;
			}
			else {
				l = m + 1;
			}
		}
		print(res);
	}
}
