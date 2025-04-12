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

#define vi vector<int>
#define sz(x) (int) x.size()
#define all(x) x.begin(), x.end()
bool find(int j, vector<vi>& g, vi& btoa, vi& vis) {
	if (btoa[j] == -1) return 1;
	vis[j] = 1; int di = btoa[j];
	for (int e : g[di])
		if (!vis[e] && find(e, g, btoa, vis)) {
			btoa[e] = di;
			return 1;
		}
	return 0;
}
int dfsMatching(vector<vi>& g, vi& btoa) {
	vi vis;
	rep(i,0,sz(g)) {
		vis.assign(sz(btoa), 0);
		for (int j : g[i])
			if (find(j, g, btoa, vis)) {
				btoa[j] = i;
				break;
			}
	}
	return sz(btoa) - (int)count(all(btoa), -1);
}

bool check(vector<int> &x, vector<int> &y, vector<int> &a, vector<int> &b, __int128_t m) {
	int n = x.size();
	vector<vector<int>> graph(n);
	rep(i, 0, n) {
		rep(j, 0, n) {
			__int128_t p = x[i] - a[j], q = y[i] - b[j];
			p *= p;
			q *= q;
			if (p + q <= m) {
				// print(i, j, (double) (p + q), (double) m);
				graph[i].push_back(j);
			}
		}
	}
	vector<int> res(n, -1);
	return dfsMatching(graph, res) == n;
}

int32_t main() {
	setup();

	int n;
	input(n);

	vector<int> x(n), y(n), a(n), b(n);
	rep(i, 0, n) {
		input(x[i], y[i]);
	}
	rep(i, 0, n) {
		input(a[i], b[i]);
	}

	__int128_t l = 0, r = 2e36, res = -1;
	while (l <= r) {
		__int128_t m = (l + r) / 2;
		// print((double) l, (double) r, (double) res);
		if (check(x, y, a, b, m)) {
			res = m;
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}

	// long double s = 0, e = 2e18, ans = 0;
	// while (e - s > 1e-6) {
	// 	long double m = (s + e) / 2;
	// 	debug(s, e);
	// 	if (m * m <= res) {
	// 		ans = m;
	// 		s = m + 1e-6;
	// 	}
	// 	else {
	// 		e = m - 1e-6;
	// 	}
	// }
	cout << setprecision(40) << fixed;
	print(sqrtf64x(res));
	// print(ans);
}
