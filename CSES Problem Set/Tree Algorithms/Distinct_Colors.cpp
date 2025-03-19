#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define int long long
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

void dfs(int u, int w, vector<vector<int>> &graph, vector<int> &l, vector<int> &p, vector<int> &q) {
	l.push_back(u);
	p[u] = l.size() - 1;
	for (int v : graph[u]) {
		if (v != w) {
			dfs(v, u, graph, l, p, q);
		}
	}
	q[u] = l.size() - 1;
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
	setup();

	int n;
	input(n);

	vector<int> a(n);
	arrput(a);

	vector<vector<int>> graph(n);
	rep(i, 0, n - 1) {
		int u, v;
		input(u, v);

		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}

	vector<int> l, p(n), q(n);
	dfs(0, -1, graph, l, p, q);

	vector<vector<pair<int, int>>> queries(n);
	rep(u, 0, n) {
		queries[p[u]].push_back({q[u], u});
	}

	vector<int> b(n);
	rep(i, 0, n) {
		b[i] = a[l[i]];
	}

	BIT bit(n);
	map<int, int> last_index;
	vector<int> solution(n, -1);
	for (int i = n - 1; i >= 0; i--) {
		int val = b[i];
		if (last_index.count(val) > 0) bit.update(last_index[val], -1);
		last_index[val] = i;
		bit.update(i, 1);
 
		for (auto &qr : queries[i]) {
			solution[qr.second] = bit.query(qr.first);
		}
	}
 
	for (auto &a : solution) { cout << a << " "; }

}
