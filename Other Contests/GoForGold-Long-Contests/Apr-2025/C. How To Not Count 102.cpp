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

const __int128_t INF = (int) 1e18 + 1;
map<array<int, 3>, int> memo;
int calc(int i, int x, bool z, int n, int m, vector<int> &a, vector<int> &b, vector<__int128_t> &p) {
	if (x < 1 or x > m) {
		return 0;
	}

	if (z) {
		__int128_t y = x;
		if (i > 0) {
			y -= b[i - 1] <= x;
		}
		if (i > 1) {
			y -= b[i - 2] <= x;
		}
		// print((int) y, i, x, z, p[n - i - 1]);
		return min(INF, y * p[n - i - 1]);
	}

	if (i == n) {
		return 0;
	}

	if (x < a[i]) {
		return 0;
	}

	array<int, 3> k = {i, x, z};
	if (x == m and memo.count(k)) {
		return memo[k];
	}

	__int128_t y = x - a[i];
	if (i > 0) {
		y -= a[i] < a[i - 1] and a[i - 1] <= x;
	}
	if (i > 1) {
		y -= a[i] < a[i - 2] and a[i - 2] <= x;
	}
	y = min(INF, y * p[n - i - 1]);
	if (i == 0 or a[i] != a[i - 1] and (i == 1 or a[i] != a[i - 2])) {
		y += calc(i + 1, m, false, n, m, a, b, p);
	}
	y = min(INF, y);
	if (x == m) {
		memo[k] = y;
	}
	return y;
}

int32_t main() {
	setup();

	int n, m, k;
	input(n, m, k);

	vector<__int128_t> p(n, 1);
	rep(i, 1, n - 1) {
		p[i] = min(INF, p[i - 1] * (m - 2));
	}
	p[n - 1] = min(INF, p[n - 2] * (m - 1));

	vector<int> a(n);
	arrput(a);

	vector<int> b(a.begin(), a.end());
	if (calc(0, m, false, n, m, a, b, p) < k) {
		print(-1);
		return 0;
	}

	bool flag = false;
	rep(i, 0, n) {
		int l = flag ? 1 : a[i], r = m;
		if (i > 0 and l == b[i - 1] or i > 1 and l == b[i - 2]) {
			l++;
		}
		if (i > 0 and l == b[i - 1] or i > 1 and l == b[i - 2]) {
			l++;
		}
		if (i > 0 and b[i] == b[i - 1] or i > 1 and b[i] == b[i - 2]) {
			b[i]++;
		}
		if (i > 0 and b[i] == b[i - 1] or i > 1 and b[i] == b[i - 2]) {
			b[i]++;
		}
		int o = l;
		while (l <= r) {
			int x = (l + r) / 2;
			if (calc(i, x, flag, n, m, a, b, p) >= k) {
				b[i] = x;
				r = x - 1;
			}
			else {
				l = x + 1;
			}
		}
		k -= calc(i, b[i] - 1, flag, n, m, a, b, p);
		if (i > 0 and b[i] == b[i - 1] or i > 1 and b[i] == b[i - 2]) {
			b[i]--;
		}
		if (i > 0 and b[i] == b[i - 1] or i > 1 and b[i] == b[i - 2]) {
			b[i]--;
		}
		if (b[i] > a[i]) {
			flag = true;
		}
	}
	arrprint(b);

	// assert(*min_element(b.begin(), b.end()) > 0);
	// assert(*max_element(b.begin(), b.end()) <= m);
	// rep(i, 1, b.size()) assert(b[i] != b[i - 1]);
	// rep(i, 2, b.size()) assert(b[i] != b[i - 2]);
}
