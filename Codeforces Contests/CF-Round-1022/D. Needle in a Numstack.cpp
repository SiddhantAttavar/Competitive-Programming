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

const int N = 1e6;
int c[N];

int t = 0;
int query(int i) {
	t++;
	assert(t <= 250);
	// return c[i];
	print('?', i + 1);
	cout.flush();
	int x;
	input(x);
	return x;
}

int32_t main() {
	int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);
		t = 0;

		// rep(i, 0, n) {
		// 	input(c[i]);
		// }
		// print(n, k);

		if (n == 2 * k) {
			print('!', k, k);
			cout.flush();
			continue;
		}

		vector<int> a(k), b(k);
		rep(i, 0, k) {
			a[i] = query(i);
		}
		rep(i, 0, k) {
			b[i] = query(n - i - 1);
		}

		int u = -1;
		rep(i, n - k, n) {
			if (a[i % k] != b[n - i - 1]) {
				u = i;
				break;
			}
		}
		// print(u, a[u % k]);

		if (u == -1) {
			print('!', -1);
			cout.flush();
			continue;
		}

		int p = query(u % k);
		int l = 0, r = u / k, x = -1;
		u %= k;
		while (l <= r) {
			int m = (l + r) / 2;
			if (query(m * k + u) == p) {
				x = m * k + u;
				l = m + 1;
			}
			else {
				r = m - 1;
			}
		}

		l = x;
		r = x + k;
		while (query(l) == a[l % k]) {
			l++;
		}
		l--;
		while (query(r) == b[(n - r - 1) % k]) {
			r--;
		}
		r++;

		l = min(l, n - k - 1);
		r = max(r, k);
		l++;
		if (l == r) {
			print('!', l, n - l);
		}
		else {
			print('!', -1);
		}
		cout.flush();
	}
}
