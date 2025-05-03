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

	vector<vector<int>> e;
	rep(i, 0, m) {
		int l, r, s;
		input(l, r, s);
		e.push_back({r, l - 1, -s});
		e.push_back({l - 1, r, s});
	}
	rep(i, 0, n) {
		e.push_back({i + 1, i, -1});
	}

	vector<int> d(n + 1, 1e18);
	d[n] = 0;
	rep(i, 0, n) {
		for (vector<int> v : e) {
			d[v[1]] = min(d[v[1]], d[v[0]] + v[2]);
		}
	}
	for (vector<int> v : e) {
		if (d[v[0]] + v[2] < d[v[1]]) {
			print(-1);
			return 0;
		}
	}

	print(-d[0]);
}
