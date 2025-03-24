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

void dfs(int u, vector<vector<int>> &graph, vector<int> &a, int d) {
	for (int v : graph[u]) {
		dfs(v, graph, a, d + 1);
	}
	if (u < a.size()) {
		a[u] = d;
	}
}

int32_t main() {
	setup();

	int n;
	input(n);

	vector<int> p(n);
	arrput(p);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	rep(i, 0, n) {
		pq.push({p[i], i});
	}

	vector<int> par(2 * n, -1);
	int t = n;
	rep(i, 0, n - 1) {
		pair<int, int> x = pq.top();
		pq.pop();
		pair<int, int> y = pq.top();
		pq.pop();

		par[x.second] = t;
		par[y.second] = t;
		pq.push({x.first + y.first, t});
		t++;
	}

	vector<int> v(2 * n);
	for (int i = 2 * n - 3; i >= 0; i--) {
		v[i] = v[par[i]] + 1;
	}

	int res = 0;
	rep(i, 0, n) {
		res += v[i] * p[i];
	}
	print(res);
}
