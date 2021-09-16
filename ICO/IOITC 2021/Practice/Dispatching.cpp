#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define print(msg) cout << msg << endl
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << " ";} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
const int MOD = 1e9 + 7;

int n, m;
unsigned long long res = 0;
vector<vector<int>> graph;
vector<vector<int>> a;
vector<int> c;
vector<ll> l;

void merge(vector<int> &a, vector<int> &b) {
	vector<int> res;
	int l = 0, r = 0;
	int sum = 0;
	while (l < a.size() || r < b.size()) {
		if (r < b.size() && (l == a.size() || a[l] > b[r])) {
			if (sum + b[r] <= m) {
				res.push_back(b[r]);
				sum += b[r];
				r++;
			}
			else {
				break;
			}
		}
		else {
			if (sum + a[l] <= m) {
				res.push_back(a[l]);
				sum += a[l];
				l++;
			}
			else {
				break;
			}
		}
	}
	a = res;
}

void dfs(int u) {
	a[u] = {c[u]};
	for (int v : graph[u]) {
		dfs(v);
		merge(a[u], a[v]);
	}
	res = max(res, l[u] * a[u].size());
}

int main() {
	setup();
	input(n, m);

	graph.resize(n);
	a.resize(n);
	c.resize(n);
	l.resize(n);

	range(i, 0, n) {
		int p;
		input(p, c[i], l[i]);
		if (p != 0) {
			graph[p - 1].push_back(i);
		}
	}

	dfs(0);
	print(res);
}