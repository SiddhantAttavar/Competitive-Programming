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
const int MOD = (int) 1e9 + 7; //998244353

struct chash {
	int operator()(vector<int> const& vec) {
		sort(vec.begin(), vec.end());
		int seed = vec.size();
		for(auto x : vec) {
			x = ((x >> 16) ^ x) * 0x45d9f3b;
			x = ((x >> 16) ^ x) * 0x45d9f3b;
			x = (x >> 16) ^ x;
			seed ^= x + 0x9e3779b9 + (seed << 6) + (seed >> 2);
		}
		return seed;
	}
};

void dfs(int u, vector<vector<int>> &graph, vector<int> &hash , gp_hash_table<vector<int>, int, chash> &s) {
	vector<int> c;
	for (int v : graph[u]) {
		dfs(v, graph, hash, s);
		c.push_back(hash[v]);
	}
	if (s.find(c) == s.end()) {

	}
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<vector<int>> g1(n), g2(m);
		range(i, 0, n - 1) {
			int p;
			input(p);
			g1[p - 1].push_back(i);
		}
		range(i, 0, m - 1) {
			int p;
			input(p);
			g2[p - 1].push_back(i);
		}

		vector<int> hash1(n, 0);
		gp_hash_table<vector<int>, int, chash> s;
		dfs(0, g1, hash1, s);
	}
}
