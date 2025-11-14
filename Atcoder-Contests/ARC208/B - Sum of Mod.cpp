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

int get(int n, int x) {
	int y = x;
	rep(i, 0, n - 1) {
		y = y / 2 + 1;
	}
	return x - y;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		int l = 1, r = 2 * k + 1, x = -1;
		while (l <= r) {
			int m = (l + r) / 2;
			if (get(n, m) >= k) {
				x = m;
				r = m - 1;
			}
			else {
				l = m + 1;
			}
		}
		assert(x != -1);

		vector<int> res(n);
		res[n - 1] = x;
		int o = k;
		for (int i = n - 2; i >= 0; i--) {
			int t = min(k, (res[i + 1] - 1) / 2);
			res[i] = res[i + 1] - t;
			assert(2 * res[i] > res[i + 1]);
			k -= t;
		}
		arrprint(res);
		cout.flush();

		int z = 0;
		rep(i, 1, n) {
			z += res[i] % res[i - 1];
		}
		assert(z == o);
	}
}
