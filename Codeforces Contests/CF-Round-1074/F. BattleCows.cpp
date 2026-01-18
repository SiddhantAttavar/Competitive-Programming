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
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

void build(int l, int r, int c, vi &a, vi &s) {
	if (l == r) {
		s[c] = a[l];
		return;
	}

	int m = (l + r) / 2;
	build(l, m, 2 * c + 1, a, s);
	build(m + 1, r, 2 * c + 2, a, s);
	s[c] = s[2 * c + 1] ^ s[2 * c + 2];
}

int solve(int z, int i, int l, int r, int c, vi &s) {
	if (l == r) {
		return 0;
	}

	int m = (l + r) / 2;
	int x = s[2 * c + 1], y = s[2 * c + 2];
	if (i <= m) {
		x ^= z;
	}
	else {
		y ^= z;
	}
	if (x >= y) {
		if (i <= m) {
			return solve(z, i, l, m, 2 * c + 1, s);
		}
		return solve(z, i, m + 1, r, 2 * c + 2, s) + (m - l + 1);
	}

	if (i <= m) {
		return solve(z, i, l, m, 2 * c + 1, s) + (r - m);
	}
	return solve(z, i, m + 1, r, 2 * c + 2, s);
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, q;
		input(n, q);

		vi a(1 << n);
		arrput(a);

		vi s(2 << n);
		build(0, (1 << n) - 1, 0, a, s);

		while (q--) {
			int i, x;
			input(i, x);
			print(solve(x ^ a[i - 1], i - 1, 0, (1 << n) - 1, 0, s));
		}
	}
}
