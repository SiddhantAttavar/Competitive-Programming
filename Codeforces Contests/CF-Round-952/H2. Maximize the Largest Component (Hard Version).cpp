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

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<string> a(n);
		arrPut(a);

		vector<vector<bool>> v(n, vector<bool>(m, false));
		range(i, 0, n) {
			range(j, 0, m) {
				v[i][j] = a[i][j] == '.';
			}
		}

		vector<vector<int>> l;
		range(i, 0, n) {
			range(j, 0, m) {
				if (v[i][j]) {
					continue;
				}

				vector<int> c = {i, i, j, j, 0};
				queue<pair<int, int>> q;
				q.push({i, j});
				v[i][j] = true;
				while (!q.empty()) {
					int x, y;
					tie(x, y) = q.front();
					q.pop();

					c[0] = min(c[0], x);
					c[1] = max(c[1], x);
					c[2] = min(c[2], y);
					c[3] = max(c[3], y);
					c[4]++;

					if (x > 0 and !v[x - 1][y]) {
						v[x - 1][y] = true;
						q.push({x - 1, y});
					}
					if (x < n - 1 and !v[x + 1][y]) {
						v[x + 1][y] = true;
						q.push({x + 1, y});
					}
					if (y > 0 and !v[x][y - 1]) {
						v[x][y - 1] = true;
						q.push({x, y - 1});
					}
					if (y < m - 1 and !v[x][y + 1]) {
						v[x][y + 1] = true;
						q.push({x, y + 1});
					}
				}
				l.push_back(c);
			}
		}

		vector<vector<vector<int>>> p(4, vector<vector<int>>(n, vector<int>(m)));
		int x = 0;
		for (vector<int> v : l) {
			p[0][v[1]][v[3]] += v[4];
			p[1][v[1]][v[2]] += v[4];
			p[2][v[0]][v[3]] += v[4];
			p[3][v[0]][v[2]] += v[4];
			x += v[4];
		}

		range(i, 0, n) {
			range(j, 0, m) {
				if (i) {
					p[0][i][j] += p[0][i - 1][j];
					if (j) {
						p[0][i][j] -= p[0][i - 1][j - 1];
					}
				}
				if (j) {
					p[0][i][j] += p[0][i][j - 1];
				}
			}
		}
		range(i, 0, n) {
			for (int j = m - 1; j >= 0; j--) {
				if (i) {
					p[1][i][j] += p[1][i - 1][j];
					if (j < m - 1) {
						p[1][i][j] -= p[1][i - 1][j + 1];
					}
				}
				if (j < m - 1) {
					p[1][i][j] += p[1][i][j + 1];
				}
			}
		}
		for (int i = n - 1; i >= 0; i--) {
			range(j, 0, m) {
				if (i < n - 1) {
					p[2][i][j] += p[2][i + 1][j];
					if (j) {
						p[2][i][j] -= p[2][i + 1][j - 1];
					}
				}
				if (j) {
					p[2][i][j] += p[2][i][j - 1];
				}
			}
		}
		for (int i = n - 1; i >= 0; i--) {
			for (int j = m - 1; j >= 0; j--) {
				if (i < n - 1) {
					p[3][i][j] += p[3][i + 1][j];
					if (j < m - 1) {
						p[3][i][j] -= p[3][i + 1][j + 1];
					}
				}
				if (j < m - 1) {
					p[3][i][j] += p[3][i][j + 1];
				}
			}
		}

		vector<int> e(n, 0), f(m, 0);
		range(i, 0, n) {
			range(j, 0, m) {
				e[i] += a[i][j] == '.';
				f[j] += a[i][j] == '.';
			}
		}

		int res = 0;
		range(i, 0, n) {
			range(j, 0, m) {
				int c = x + e[i] + f[j] - (a[i][j] == '.');
				if (i >= 2 and j >= 2) {
					c -= p[0][i - 2][j - 2];
				}
				if (i >= 2 and j < m - 2) {
					c -= p[1][i - 2][j + 2];
				}
				if (i < n - 2 and j >= 2) {
					c -= p[2][i + 2][j - 2];
				}
				if (i < n - 2 and j < m - 2) {
					c -= p[3][i + 2][j + 2];
				}
				res = max(res, c);
			}
		}

		print(res);
		cout.flush();
	}
}
