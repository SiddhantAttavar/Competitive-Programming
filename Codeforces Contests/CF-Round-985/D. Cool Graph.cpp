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

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<set<int>> graph(n);
		rep(i, 0, m) {
			int u, v;
			input(u, v);

			graph[u - 1].insert(v - 1);
			graph[v - 1].insert(u - 1);
		}

		set<int> s;
		rep(i, 0, n) {
			if (graph[i].size() > 1) {
				s.insert(i);
			}
		}

		vector<vector<int>> res;
		while (!s.empty()) {
			int u = *s.begin();

			int v = *graph[u].begin();
			graph[u].erase(v);
			graph[v].erase(u);

			int w = *graph[u].begin();
			graph[u].erase(w);
			graph[w].erase(u);

			if (graph[v].count(w)) {
				graph[v].erase(w);
				graph[w].erase(v);
			}
			else {
				graph[v].insert(w);
				graph[w].insert(v);
			}

			if (s.count(u) and graph[u].size() < 2) {
				s.erase(u);
			}
			if (s.count(v) and graph[v].size() < 2) {
				s.erase(v);
			}
			if (s.count(w) and graph[w].size() < 2) {
				s.erase(w);
			}

			if (!s.count(v) and graph[v].size() >= 2) {
				s.insert(v);
			}
			if (!s.count(w) and graph[w].size() >= 2) {
				s.insert(w);
			}

			res.push_back({u + 1, v + 1, w + 1});
		}

		vector<vector<int>> v;
		vector<bool> l(n, false);
		rep(i, 0, n) {
			if (l[i]) {
				continue;
			}

			v.push_back({i});
			if (graph[i].size()) {
				l[*graph[i].begin()] = true;
				v.back().push_back(*graph[i].begin());
			}
		}

		vector<int> a;
		vector<pair<int, int>> b;
		for (vector<int> i : v) {
			if (i.size() == 1) {
				a.push_back(i[0]);
			}
			else {
				b.push_back({i[0], i[1]});
			}
		}

		if (a.size() == n) {
			assert(res.size() <= 2 * max(n, m));
			print(res.size());
			for (vector<int> v : res) {
				arrprint(v);
			}
			continue;
		}

		int x, y;
		tie(x, y) = b.back();
		b.pop_back();

		for (int z : a) {
			res.push_back({x + 1, y + 1, z + 1});
			y = z;
		}

		for (pair<int, int> p : b) {
			res.push_back({x + 1, p.first + 1, p.second + 1});
		}

		assert(res.size() <= 2 * max(n, m));
		print(res.size());
		for (vector<int> v : res) {
			arrprint(v);
		}
	}
}
