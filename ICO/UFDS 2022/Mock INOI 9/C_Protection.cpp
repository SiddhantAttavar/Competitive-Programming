#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

bool dfs(vector<vector<int>> &graph, int u, int p, vector<int> &fin, int l) {	
	if (l <= u) {
		fin[u] = u;
	}
	for (int v : graph[u]) {
		if (v != p) {
			if (dfs(graph, v, u, fin, l)) {
				fin[u] = min(fin[u], fin[v]);
			}
		}
	}
	return fin[u];
}

int32_t main() {
	setup();
	int n, k; input(n, k);
	vector<vector<int>> graph(n);
	range(i, 0, n - 1) {
		int u, v; input(u, v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	vector<int> nxt(n), prv(n), v;
	range(u, 0, n) {
		if (graph[u].size() == 1) {
			prv[u] = -1;
			int c = graph[u][0];
			nxt[u] = c;
			v.push_back(u);
			while (graph[c].size() == 2) {
				v.push_back(c);
				prv[c] = u;
				for (int v : graph[c]) {
					if (v != u) {
						nxt[c] = v;
						u = c;
						c = v;
						break;
					}
				}
			}
			nxt[c] = -1;
			prv[c] = u;
			v.push_back(c);
			break;
		}
	}

	vector<int> ind(n);
	range(i, 0, n) {
		ind[v[i]] = i;
	}
	stack<int> l, r;
	l.push(0);
	r.push(0);
	int x = 0, y = 0, res = 1;
	while (x <= y and y < n) {
		res = max(res, y - x + 1);
		y++;
		if (l.empty() or ind[y] < l.top()) {
			l.push(ind[y]);
		}
		if (r.empty() or ind[y] > r.top()) {
			r.push(ind[y]);
		}
		while (!l.empty() and !r.empty() and (r.top() - l.top()) + 1 > k) {
			if (!l.empty() and l.top() == x) {
				l.pop();
			}
			else if (!r.empty() and r.top() == x) {
				r.pop();
			}
			x++;
		}
		res = max(res, y - x + 1);
	}
	print(res);
}
