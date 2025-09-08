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

void dfs(int u, vector<vector<int>> &graph, vector<int> &d) {
	for (int v : graph[u]) {
		d[v] = d[u] + 1;
		dfs(v, graph, d);
	}
}

const int N = 2e5;
template<int l = 1>
int check(vector<int> &v, int m, int x, int y) {
	if (l < v.size() + 1) {
		return check<min(2 * l, N)>(v, m, x, y);
	}

	map<int, int> w;
	rep(i, 0, m + 1) {
		w[v[i]]++;
	}

	vector<int> a;
	// for (auto [k, v] : w) {
	// 	while (v >= 3) {
	// 		w[2 * k] += v / 3;
	// 		v -= 2 * (v / 3);
	// 	}
	// 	while (v--) {
	// 		a.push_back(k);
	// 	}
	// }
	a = vector<int>(v.begin(), v.begin() + m + 1);

	bitset<l> b = 1;
	for (int i : a) {
		b |= b << i;
	}

	for (int i = x; i >= 0; i--) {
		if (b[i]) {
			return (accumulate(v.begin(), v.begin() + m + 1, 0ll) - i) <= y;
		}
	}
	return false;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		vector<vector<int>> graph(n);
		rep(i, 0, n - 1) {
			int v;
			input(v);
			graph[v - 1].push_back(i + 1);
		}

		vector<int> d(n, 0);
		dfs(0, graph, d);

		vector<int> v(n, 0);
		rep(i, 0, n) {
			v[d[i]]++;
		}

		int l = 0, r = n - 1, res = 0;
		rep(i, 0, n) {
			if (graph[i].empty()) {
				r = min(r, d[i]);
			}
		}
		while (l <= r) {
			int m = (l + r) / 2;
			if (check(v, m, k, n - k)) {
				res = m + 1;
				l = m + 1;
			}
			else {
				r = m - 1;
			}
		}
		print(res);
	}
}
