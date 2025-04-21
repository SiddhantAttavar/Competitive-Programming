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
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		vector<int> a(n);
		arrput(a);

		vector<int> p(n);
		p[0] = a[0] <= k;
		rep(i, 1, n) {
			p[i] = p[i - 1] + (a[i] <= k);
		}
		rep(i, 0, n) {
			p[i] = 2 * p[i] - i;
		}

		vector<int> q(n, -1e8);
		q[n - 2] = p[n - 2];
		for (int i = n - 3; i >= 0; i--) {
			q[i] = max(p[i], q[i + 1]);
		}

		bool flag = false;
		rep(i, 0, n - 2) {
			if (p[i] > 0 and q[i + 1] >= p[i]) {
				flag = true;
				break;
			}
		}

		if (flag) {
			print("YES");
			continue;
		}

		reverse(a.begin(), a.end());
		p[0] = a[0] <= k;
		rep(i, 1, n) {
			p[i] = p[i - 1] + (a[i] <= k);
		}
		rep(i, 0, n) {
			p[i] = 2 * p[i] - i;
		}

		q[n - 2] = p[n - 2];
		for (int i = n - 3; i >= 0; i--) {
			q[i] = max(p[i], q[i + 1]);
		}

		flag = false;
		rep(i, 0, n - 2) {
			if (p[i] > 0 and q[i + 1] >= p[i]) {
				flag = true;
				break;
			}
		}

		if (flag) {
			print("YES");
			continue;
		}

		int x = 0;
		vector<int> r(n);
		r[0] = p[0];
		rep(i, 1, n) {
			r[i] = max(r[i - 1], p[i]);
		}
		for (int i = n - 1; i >= 2; i--) {
			x += a[i] <= k;
			if (2 * x >= (n - i) and r[i - 2] > 0) {
				flag = true;
				break;
			}
		}

		if (flag) {
			print("YES");
		}
		else {
			print("NO");
		}
	}
}
