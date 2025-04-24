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
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<int> a(n), b(m);
		arrput(a);
		arrput(b);

		vector<int> l(n), r(n);
		l[0] = a[0] >= b[0];
		rep(i, 1, n) {
			l[i] = l[i - 1] + (l[i - 1] < m and a[i] >= b[l[i - 1]]);
		}
		r[n - 1] = a[n - 1] >= b[m - 1] ? m - 2 : m - 1;
		for (int i = n - 2; i >= 0; i--) {
			r[i] = r[i + 1] - (r[i + 1] >= 0 and a[i] >= b[r[i + 1]]);
		}

		if (l[n - 1] == m) {
			print(0);
			continue;
		}

		int res = 1e18;
		if (r[0] == 0) {
			res = min(res, b[0]);
		}
		rep(i, 1, n) {
			if (l[i - 1] == r[i]) {
				res = min(res, b[r[i]]);
			}
		}
		if (l[n - 1] == m - 1) {
			res = min(res, b[m - 1]);
		}

		if (res == 1e18) {
			print(-1);
		}
		else {
			print(res);
		}
	}
}
