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

	int n, m, d, x;
	input(n, m, d, x);

	int c = 0;
	vector<int> v;
	rep(i, 0, n) {
		int l, r;
		input(l, r);

		v.push_back(l - c - 1);
		c = r;
	}
	v.push_back(m - c);
	n = v.size();
	rep(i, 1, n - 1) {
		v[i] -= d;
	}

	int res = 1e18;
	rep(i, 0, n) {
		vector<int> a(n, 0);
		rep(j, 0, n) {
			a[abs(i - j)] += v[j];
		}
		int y = x + d, c = 0;
		rep(j, 0, n) {
			int t = min(y, a[j]);
			c += t * j;
			y -= t;
		}
		if (y == 0) {
			res = min(res, c);
		}
	}

	if (res == 1e18) {
		print(-1);
	}
	else {
		print(res);
	}
}
