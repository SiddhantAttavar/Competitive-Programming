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
		int n;
		input(n);

		vector<int> a(n);
		arrput(a);

		map<int, int> m;
		for (int i : a) {
			m[i]++;
		}

		int c = 1;
		map<int, int> t;
		for (pair<int, int> p : m) {
			t[p.first] = c++;
		}
		c--;

		rep(i, 0, n) {
			a[i] = t[a[i]];
		}

		vector<int> w(c + 1);
		rep(i, 0, n) {
			w[a[i]]++;
		}
		if (w[c] > 1 or *max_element(w.begin(), w.end()) > 2) {
			print(-1);
			continue;
		}

		vector<int> s(c + 1, 0);
		rep(i, 0, c) {
			s[i + 1] = s[i] + w[i + 1];
		}

		vector<int> p(c + 1, 1e18), q(c + 1, 1e18);
		ordered_set o;
		rep(i, 0, n) {
			p[a[i]] = min(p[a[i]], (int) (o.size() - o.order_of_key(a[i] + 1)));
			o.insert(a[i]);
		}
		o.clear();
		for (int i = n - 1; i >= 0; i--) {
			q[a[i]] = min(q[a[i]], (int) (o.size() - o.order_of_key(a[i] + 1)));
			o.insert(a[i]);
		}

		int res = 0;
		bool x = false, y = false;
		rep(i, 1, c) {
			if (w[i] == 2) {
				res += p[i] + q[i];
				x = true;
				y = true;
			}
			else if (p[i] > q[i]) {
				res += q[i];
				y = true;
			}
			else {
				res += p[i];
				x = true;
			}
		}

		if (!x) {
			int z = 1e18;
			rep(i, 1, c) {
				z = min(z, p[i] - q[i]);
			}
			res += z;
		}

		if (!y) {
			int z = 1e18;
			rep(i, 1, c) {
				z = min(z, q[i] - p[i]);
			}
			res += z;
		}

		print(res);
	}
}
