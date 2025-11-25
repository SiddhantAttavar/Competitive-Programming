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

bool debug = false;
int K = 300;
vector<int> path;

bool query(int u) {
	assert(K);
	K--;
	print('?', u + 1);
	cout.flush();
	if (debug) {
		if (find(path.begin(), path.end(), u) == path.end()) {
			if (path.size() > 1) {
				path.pop_back();
			}
			return false;
		}
		return true;
	}
	int x;
	input(x);
	return x;
}

void dfs(int u, vector<vector<int>> &graph, vector<int> &p, vector<int> &s, vector<int> &l) {
	l[u] += graph[u].empty();
	for (int v : graph[u]) {
		if (v != p[u]) {
			p[v] = u;
			dfs(v, graph, p, s, l);
			s[u] += s[v];
			l[u] += l[v];
		}
	}
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);
		K = 300;

		vector<vector<int>> graph(n);
		rep(i, 0, n - 1) {
			int u, v;
			input(u, v);

			graph[u - 1].push_back(v - 1);
			graph[v - 1].push_back(u - 1);
		}

		vector<int> par(n, -1), s(n, 1), l(n, 0);
		dfs(0, graph, par, s, l);
		rep(i, 1, n) {
			graph[i].erase(find(graph[i].begin(), graph[i].end(), par[i]));
		}

		if (debug) {
			int u;
			input(u);
			u--;

			path.clear();
			while (u != -1) {
				path.push_back(u);
				u = par[u];
			}
			reverse(path.begin(), path.end());
		}

		int r = 0, c = 0;
		while (!graph[r].empty()) {
			vector<int> p(n, -1), s(n, 1), l(n, 0);
			dfs(r, graph, p, s, l);

			pair<int, int> u = {n + 1, r};
			rep(v, 0, n) {
				if (l[v] and v != r) {
					u = min(u, {max(s[v], s[r] - s[v] - l[r] + l[v]), v});
				}
			}

			int v = u.second;
			if (query(v)) {
				graph[par[v]].erase(find(graph[par[v]].begin(), graph[par[v]].end(), v));
				r = v;
				continue;
			}

			graph[p[v]].erase(find(graph[p[v]].begin(), graph[p[v]].end(), v));
			if (par[r] != -1) {
				graph[par[r]].push_back(r);
				r = par[r];
			}
			if (par[r] != -1) {
				vector<int>::iterator j = find(graph[par[r]].begin(), graph[par[r]].end(), r);
				if (j != graph[par[r]].end()) {
					graph[par[r]].erase(j);
				}
			}

			p.assign(n, -1);
			s.assign(n, 1);
			l.assign(n, 0);
			dfs(r, graph, p, s, l);
			rep(i, 0, n) {
				if (l[i] == 1 and graph[i].empty() and par[i] != -1) {
					assert(find(graph[par[i]].begin(), graph[par[i]].end(), i) != graph[par[i]].end());
					graph[par[i]].erase(find(graph[par[i]].begin(), graph[par[i]].end(), i));
				}
			}
			c++;
		}
		print('!', r + 1);
		cout.flush();
		assert(c <= 160);

		if (debug) {
			assert(r == path.back());
		}
	}
}
