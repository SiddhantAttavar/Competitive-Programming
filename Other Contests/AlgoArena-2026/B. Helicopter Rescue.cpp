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

int get(vi &a, int t, int g) {
	int c = 0, res = 1;
	for (int i : a) {
		if (i * g > t) {
			return 1e18;
		}
		if ((c + i) * g <= t) {
			c += i;
			continue;
		}
		res++;
		c = i;
	}
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k, g;
		input(n, k, g);

		vi a(n);
		arrput(a);

		int l = 0, r = 1e18, res = 1e18;
		while (l <= r) {
			int m = (l + r) / 2;
			if (get(a, m, g) <= k) {
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
