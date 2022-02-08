#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

vector<map<pair<int, int>, int>> graph(1);
int n, S = 0;
vector<vector<int>> s;
vector<int> k;
vector<vector<int>> p, q;
vector<int> numChild;

void dfs1(int u) {
	for (pair<pair<int, int>, int> e : graph[u]) {
		int j, x, v = e.second;
		tie(j, x) = e.first;
		dfs1(v);
		numChild[u] += numChild[v];
	}
}

int dfs2(int u, int c) {
	int res = c;
	for (pair<pair<int, int>, int> e : graph[u]) {
		int j, x, v = e.second;
		tie(j, x) = e.first;
		res = min(res, dfs2(v, c + (n - 2 * numChild[v]) * x));
	}
	return res;
}

int32_t main() {
	setup();
	
	input(n);
	k.resize(n);
	p.resize(n);
	q.resize(n);
	range(i, 0, n) {
		input(k[i]);
		p[i].resize(k[i]);
		q[i].resize(k[i]);
		range(j, 0, k[i]) {
			input(p[i][j], q[i][j]);
		}
	}

	int h = 0;
	while ((1 << h) <= 1e6) {
		h++;
	}

	vector<int> ind(n);
	range(i, 0, n) {
		ind[i] = i;
	}
	sort(ind.begin(), ind.end(), [](int a, int b) {
		range(i, 0, min(k[a], k[b])) {
			if (p[a][i] != p[b][i]) {
				return p[a][i] < p[b][i];
			}

			if (q[a][i] != q[b][i]) {
				return q[a][i] < q[b][i];
			}
		}
		return k[a] < k[b];
	});

	int c = 1;
	numChild.push_back(0);
	for (int i : ind) {
		int u = 0;
		range(j, 0, k[i]) {
			S += q[i][j];
			range(x, 0, h) {
				pair<int, int> e;
				if ((1 << x) > q[i][j]) {
					e = {p[i][j], q[i][j]};
				}
				else {
					e = {p[i][j], 1 << x};
				}
				map<pair<int, int>, int>::iterator it = graph[u].lower_bound({p[i][j], -1});
				if (it == graph[u].end() or (*it).first.first != e.first) {
					graph[u][e] = c;
					numChild.push_back(0);
					graph.push_back(map<pair<int, int>, int>());
					c++;
				}
				else {
					assert((*it).first.second <= e.second);
					e = (*it).first;
				}
				u = graph[u][e];
				q[i][j] -= e.second;
				if (q[i][j] == 0) {
					break;
				}
			}
		}
		numChild[u]++;
	}

	/**
	range(i, 0, graph.size()) {
		cout << i << ": \n";
		for (pair<pair<int, int>, int> p : graph[i]) {
			print(p.first.first, p.first.second, p.second);
		}
	}
	**/

	dfs1(0);
	print(dfs2(0, S));
}
