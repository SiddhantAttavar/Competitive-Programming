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

#define vi vector<int>
#define sz(x) (int) x.size()
vi val, comp, z, cont;
int Time, ncomps;
template<class G, class F> int dfs(int j, G& g, F& f) {
	int low = val[j] = ++Time, x; z.push_back(j);
	for (auto e : g[j]) if (comp[e] < 0)
		low = min(low, val[e] ?: dfs(e,g,f));

	if (low == val[j]) {
		do {
			x = z.back(); z.pop_back();
			comp[x] = ncomps;
			cont.push_back(x);
		} while (x != j);
		f(cont); cont.clear();
		ncomps++;
	}
	return val[j] = low;
}
template<class G, class F> void scc(G& g, F f) {
	int n = sz(g);
	val.assign(n, 0); comp.assign(n, -1);
	Time = ncomps = 0;
	dfs(0, g, f);
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<vector<int>> graph(n);
		rep(i, 0, m) {
			int u, v;
			input(u, v);
			graph[u - 1].push_back(v - 1);
		}

		vector<int> res(n, -2);
		scc(graph, [&](vector<int> &v) {
			for (int i : v) {
				res[i] = 0;
			}
		});

		vector<pair<int, int>> v(n);
		rep(i, 0, n) {
			v[i] = {comp[i], i};
		}
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());

		res[0] = 1;
		for (pair<int, int> i : v) {
			int u = i.second;
			if (res[u] == -2) {
				res[u] = 0;
				continue;
			}
			for (int j : graph[u]) {
				if (comp[j] == comp[u]) {
					res[j] = -1;
					res[u] = -1;
				}
			}
			for (int j : graph[u]) {
				if (res[u] == -1) {
					res[j] = -1;
					continue;
				}
				if (res[j] == -1) {
					continue;
				}
				if (res[u] == 2) {
					res[j] = 2;
				}
				else {
					res[j] = min(2ll, res[j] + 1);
				}
			}
		}
		arrprint(res);
	}
}
