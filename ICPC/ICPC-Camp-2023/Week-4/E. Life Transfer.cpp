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

int32_t main() {
	setup();

	int n, k;
	input(n, k);

	int lc, pc, lm, pm;
	input(lc, pc, lm, pm);

	int t, d;
	input(t, d);

	vector<int> a(n);
	arrput(a);

	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());

	int res = 1e18;
	int c = 0, j = n - 1, z = 0, f = 0;
	rep(i, 0, n) {
		// add to B
		z += min(d, max(0ll, a[i] - lm));
		c += max(0ll, lm - a[i]);
		f += a[i] < lm - d;
	}

	rep(x, 0, (n + k - 1) / k + 1) {
		int y = max(0ll, n - k * x);
		while (x + y <= j) {
			// remove from B
			f -= a[j] < lm - d;
			z -= min(d, max(0ll, a[j] - lm));
			c -= max(0ll, lm - a[j]);

			// add to C
			z += min(d, a[j] - 1);
			j--;
		}

		// check
		if (z >= c and !f) {
			res = min(res, x * pc + y * pm + c * t);
		}

		// remove from B
		f -= a[x] < lm - d;
		z -= min(d, max(0ll, a[x] - lm));
		c -= max(0ll, lm - a[x]);

		// add to A
		if (a[x] < lc - d) {
			break;
		}
		z += min(d, max(0ll, a[x] - lc));
		c += max(0ll, lc - a[x]);
	}

	if (res == 1e18) {
		print(-1);
	}
	else {
		print(res);
	}
}
