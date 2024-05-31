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
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = 998244353;

void dfs(int u, vector<pair<int, int>> &tree, vector<int> &b) {
	if (tree[u].first == -1) {
		b.push_back(tree[u].second);
		return;
	}
	dfs(tree[u].first, tree, b);
	dfs(tree[u].second, tree, b);
}

int32_t main() {
	setup();
	int n, q;
	input(n, q);

	vector<int> l(q), r(q);
	arrPut(l);
	arrPut(r);

	vector<int> a(n, 0);
	vector<pair<int, int>> tree = {{-1, -1}};
	range(i, 0, q) {
		l[i]--;
		r[i]--;

		int u = a[max(l[i], r[i])];
		tree[u].first = tree.size();
		a[l[i]] = tree.size();
		tree.push_back({-1, l[i]});
		tree[u].second = tree.size();
		a[r[i]] = tree.size();
		tree.push_back({-1, r[i]});
	}

	vector<int> b;
	dfs(0, tree, b);

	map<int, int> m;
	m[b[0]] = 1;
	m[b.back()] = 1;
	range(i, 1, b.size()) {
		m[max(b[i], b[i - 1])]++;
	}

	vector<bool> c(n, false);
	for (int i : b) {
		c[i] = true;
	}

	int x = 0, res = 1;
	for (int i = n - 1; i >= 0; i--) {
		if (m.count(i)) {
			x += m[i];
		}
		if (c[i]) {
			continue;
		}

		res = (res * x) % MOD;
		x++;
	}

	print(res);
}
