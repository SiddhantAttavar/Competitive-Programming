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

void dfs(int u, int p, vector<vector<pair<int, int>>> &graph, vector<int> &x, vector<int> &l) {
	for (pair<int, int> i : graph[u]) {
		if (i.first != p) {
			x[i.first] = x[u] ^ i.second;
			l[i.first] = l[u] + 1;
			dfs(i.first, u, graph, x, l);
		}
	}
}

int solve(vector<pair<int, int>> &a, int x) {
	int res = 0;
	int l = 0, r = a.size() - 1;
	int y = 0;
	for (int i = 29; i >= 0; i--) {
		y |= x & (1 << i);
		if ((a[l].first & (1 << i)) == (a[r].first & (1 << i))) {
			res |= (x ^ a[l].first) & (1 << i);
			continue;
		}

		// print(l, r, i, x, res ^ y | (x & 1 << i));
		res |= 1 << i;
		if (x & (1 << i)) {
			r = lower_bound(a.begin(), a.end(), make_pair(res ^ y | 1 << i, 0ll)) - a.begin() - 1;
		}
		else {
			l = lower_bound(a.begin(), a.end(), make_pair(res ^ y, 0ll)) - a.begin();
		}
	}
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<vector<pair<int, int>>> graph(n);
		range(i, 0, n - 1) {
			int u, v, w;
			input(u, v, w);
			
			graph[u - 1].push_back({v - 1, w});
			graph[v - 1].push_back({u - 1, w});
		}

		vector<int> p(n, 0), l(n, 0);
		dfs(0, -1, graph, p, l);

		vector<pair<int, int>> a, b;
		range(i, 0, n) {
			if (l[i] % 2 == 0) {
				a.push_back({p[i], i});
			}
			else {
				b.push_back({p[i], i});
			}
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		vector<int> ind(n);
		range(i, 0, (int) a.size()) {
			ind[a[i].second] = i;
		}
		range(i, 0, (int) b.size()) {
			ind[b[i].second] = i;
		}

		int y = 0;
		while (m--) {
			char c;
			input(c);

			if (c == '^') {
				int x;
				input(x);
				y ^= x;
			}
			else {
				int u, x;
				input(u, x);

				u--;
				x ^= p[u];
				if (l[u] % 2 == 0) {
					int t = a[ind[u]].first;
					if (ind[u] == 0) {
						if (a.size() == 1) {
							a[0].first = x;
						}
						else {
							a[0].first = a[1].first;
						}
					}
					else {
						a[ind[u]].first = a[ind[u] - 1].first;
					}
					cout << max(solve(a, x), solve(b, x ^ y)) << ' ';
					a[ind[u]].first = t;
				}
				else {
					// for (pair<int, int> p : a) {
					// 	cout << p.first << ' ';
					// }
					// for (pair<int, int> p : b) {
					// 	cout << p.first << ' ';
					// }
					// cout << endl;
					int t = b[ind[u]].first;
					if (ind[u] == 0) {
						if (b.size() == 1) {
							b[0].first = x;
						}
						else {
							b[0].first = b[1].first;
						}
					}
					else {
						b[ind[u]].first = b[ind[u] - 1].first;
					}
					cout << max(solve(b, x), solve(a, x ^ y)) << ' ';
					b[ind[u]].first = t;
				}
			}
		}
		cout << endl;
	}
}
