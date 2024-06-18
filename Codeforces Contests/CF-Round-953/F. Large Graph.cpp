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
const int MOD = (int) 1e9 + 7;

void dfs(int u, vector<vector<int>> &graph, vector<bool> &vis) {
	vis[u] = true;
	for (int v : graph[u]) {
		if (!vis[v]) {
			dfs(v, graph, vis);
		}
	}
}

struct DSU {
	vector<int> e; void init(int N) { e = vector<int>(N,-1); }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); } 
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y) { // union by size
		x = get(x), y = get(y); if (x == y) return 0;
		if (e[x] > e[y]) swap(x,y);
		e[x] += e[y]; e[y] = x; return 1;
	}
};

int32_t main() {
	int N = 1e6;
	vector<int> spf(N + 1);
	range(i, 0, N + 1) {
		spf[i] = i;
	}
	range(i, 2,  N + 1) {
		if (spf[i] != i) {
			continue;
		}
		for (int j = i; j <= N; j += i) {
			if (spf[j] == j) {
				spf[j] = i;
			}
		}
	}

	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		vector<int> b(n);
		arrPut(b);

		int res = 0;
		range(i, 0, n) {
			res += (n - i - 1) * (b[i] == 1);
		}
		range(i, 1, n) {
			res += (i - 1) * (b[i] == 1);
		}

		vector<int> a(b.begin() + 1, b.end());
		a.insert(a.end(), b.begin(), b.end());
		b.clear();

		vector<pair<int, int>> v;
		range(i, 0, 2 * n - 1) {
			int p = -1;
			int o = a[i];
			while (o != 1) {
				if (spf[o] != p) {
					p = spf[o];
					v.push_back({p, i});
				}
				o /= spf[o];
			}
		}
		sort(v.begin(), v.end());
		a.clear();

		DSU d;
		d.init(2 * n - 1);
		res += 2 * n - 1;
		range(j, 1, v.size()) {
			if (v[j].first == v[j - 1].first and v[j - 1].second + k >= v[j].second) {
				res -= d.unite(v[j - 1].second, v[j].second);
			}
		}

		print(res);
	}
}
