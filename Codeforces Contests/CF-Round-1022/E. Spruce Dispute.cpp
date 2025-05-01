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

void dfs(int u, int w, vector<vector<int>> &graph, vector<int> &p, vector<int> &q, int &x) {
	p[u] = x++;
	for (int v : graph[u]) {
		if (v != w) {
			dfs(u, v, graph, p, q, x);
		}
	}
	q[u] = x;
}

struct BIT {
	int size;
	vector<int> bit;
	BIT(int n) : size(n), bit(n + 1) {}
	void update(int x, int v) {
		x++;
		for (; x <= size; x += x & (-x)) { bit[x] += v; }
	}
	/** @return sum of the values in [0,b] */
	int query(int b) {
		b++;
		int result = 0;
		for (; b > 0; b -= b & (-b)) { result += bit[b]; }
		return result;
	}
};

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<vector<int>> graph(n);
		rep(i, 0, n) {
			int u, v;
			input(u, v);
			graph[u - 1].push_back(v - 1);
			graph[v - 1].push_back(u - 1);
		}

		vector<int> l(n), r(n);
		int x = 0;
		dfs(0, -1, graph, l, r, x);

		vector<vector<int>> q(n);
		rep(i, 1, n) {
			q[l[i]].push_back(r[i]);
		}

		int res = 0;
		map<int, int> m;
		for (int i = n - 1; i >= 0; i--) {
			// if (m.count(a[i])) {
			//
			// }
		}
	}
}
