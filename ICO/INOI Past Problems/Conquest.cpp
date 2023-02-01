#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
// #define int long long

int n, h, q;
int w[500005];
vector<int> graph[500005];
int p[500005][21], p2[500005][21];
long long dp[500005][21][4];
int l[500005], ti[500005], to[500005];
int t;

void combine(long long *res, long long *a, long long *b) {
	long long x[4] = {
		max({a[0] + b[0], a[0] + b[2], a[1] + b[0]}),
		max({a[0] + b[1], a[0] + b[3], a[1] + b[1]}),
		max({a[2] + b[0], a[2] + b[2], a[3] + b[0]}),
		max({a[2] + b[1], a[2] + b[3], a[3] + b[1]})
	};
	res[0] = x[0];
	res[1] = x[1];
	res[2] = x[2];
	res[3] = x[3];
}

void dfs(int u) {
	ti[u] = t;
	t++;

	// print(u);
	for (int i : graph[u]) {
		if (p[u][1] != i) {
			l[i] = l[u] + 1;
			p[i][0] = i;
			p[i][1] = u;
			p2[i][0] = i;
			p2[i][1] = u;
			dp[i][0][3] = w[i];

			range(j, 1, h) {
				if (p[i][j - 1] == -1) {
					break;
				}
				if (j != 1) {
					p[i][j] = p[p[i][j - 1]][j - 1];
				}

				if (p2[i][j - 1] != -1 and p2[p2[i][j - 1]][1] != -1) {
					p2[i][j] = p2[p2[p2[i][j - 1]][1]][j - 1];
				}

				if (p2[i][j] != -1) {
					combine(dp[i][j], dp[i][j - 1], dp[p2[p2[i][j - 1]][1]][j - 1]);
				}
			}

			dfs(i);
		}
	}

	to[u] = t;
	t++;
}

pair<long long, long long> solve(int a, int b) {
	// print(a, b);
	if (a == b) {
		return {w[a], 0};
	}

	int x = l[a] - l[b] + 1;
	long long res[4] = {0, 0, 0, 0};
	for (int i = h - 1; i >= 0; i--) {
		if ((1 << i) & x) {
			combine(res, res, dp[a][i]);
			a = p2[p2[a][i]][1];
		}
	}

	// print(max({res[0], res[1], res[2], res[3]}));
	return {
		max({res[0], res[1], res[2], res[3]}),
		max({res[0], res[2]})
	};
}

pair<int, int> findLCA(int a, int b) {
	int u = a, v = b;

	if (l[a] > l[b]) {
		int x = l[a] - l[b];
		range(i, 0, h) {
			if ((1 << i) & x) {
				u = p[u][i + 1];
			}
		}
	}
	else if (l[a] < l[b]) {
		int x = l[b] - l[a];
		range(i, 0, h) {
			if ((1 << i) & x) {
				v = p[v][i + 1];
			}
		}
	}

	// print("First part done");

	if (u == v) {
		// print("Same");
		return {-1, -1};
	}

	for (int i = h - 1; i >= 0; i--) {
		// print(i, u, v);
		if (p[u][i] != p[v][i]) {
			u = p[u][i];
			v = p[v][i];
		}
	}

	// print("Second part done");

	return {u, v};
}

int32_t main() {
	//setup();
	
	// input
	input(n, q);
	h = log2(n) + 2;

	fill(w, w + n, 0);
	range(i, 0, n) {
		input(w[i]);
	}
	
	fill(graph, graph + n, vector<int>());
	range(i, 0, n - 1) {
		int u, v;
		input(u, v);
		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}

	// print("input done");

	// preprocessing
	fill(l, l + n, 0);
	fill(ti, ti + n, 0);
	fill(to, to + n, 0);
	range(i, 0, n) {
		range(j, 0, h) {
			p[i][j] = -1;
			p2[i][j] = -1;
		}
	}
	p[0][0] = 0;
	p2[0][0] = 0;
	range(i, 0, n) {
		range(j, 0, h) {
			fill(dp[i][j], dp[i][j] + 4, 0);
		}
	}
	dp[0][0][3] = w[0];
	t = 0;

	dfs(0);

	// print("preprocessing done");
	
	/* print("---");
	range(i, 0, n) {
		range(j, 0, h) {
			arrPrint(dp[i][j]);
		}
		print("");
	}
	print("---"); */

	// queries
	while (q--) {
		int a, b;
		input(a, b);
		a--;
		b--;

		if (a == b) {
			print(w[a]);
		}
		else if ((ti[a] > ti[b]) and (to[a] < to[b])) {
			print(solve(a, b).first);
		}
		else if ((ti[a] < ti[b]) and (to[a] > to[b])) {
			print(solve(b, a).first);
		}
		else {
			int a1, b1;
			tie(a1, b1) = findLCA(a, b);

			// print("LCA found");

			long long k, m, e, f;
			tie(e, k) = solve(a, a1);
			tie(f, m) = solve(b, b1);
			int u = p[a1][1];

			// print(u, a1, a2, b1, b2, x, y);

			print(max(k + m + w[u], e + f));
		}
	}
}
