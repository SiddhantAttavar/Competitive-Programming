#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
template<typename T> inline void dbg(T x) {cerr << x << '\n';}
template<typename T, typename... S> inline void dbg(T x, S... args) {cerr << x << ", "; dbg(args ...);}
#define debug(...) cerr << #__VA_ARGS__ << ": "; dbg(__VA_ARGS__);
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	setup();

	int n, m;
	input(n, m);

	vector<int> c(n);
	arrput(c);

	vector<vector<int>> a(n);
	rep(i, 0, m) {
		int k;
		input(k);
		vector<int> v(k);
		arrput(v);
		for (int j : v) {
			a[j - 1].push_back(i);
		}
	}

	int res = 1e18;
	rep(i, 0, 1 << (2 * n)) {
		int x = 0;
		vector<int> y(m, 0);
		rep(j, 0, 2 * n) {
			if (!(i & (1 << j))) {
				continue;
			}

			x += c[j % n];
			for (int k : a[j % n]) {
				y[k]++;
			}
		}

		if (*min_element(y.begin(), y.end()) >= 2) {
			res = min(res, x);
		}
	}

	print(res);
}
