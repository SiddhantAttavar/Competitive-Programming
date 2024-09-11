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

pair<int, int> end1(int i, int j, int n, int m) {
	if (j + (n - i - 1) < m) {
		return {n - 1, j + (n - i - 1)};
	}
	return {i + (m - j - 1), m - 1};
}

pair<int, int> end2(int i, int j, int n, int m) {
	if (j + i < m) {
		return {0, j + i};
	}
	return {i - (m - j - 1), m - 1};
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<vector<int>> a(n, vector<int>(m));
		range(i, 0, n) {
			arrPut(a[i]);
		}

		bool flag = false;
		if (n > m) {
			flag = true;
			vector<vector<int>> b(m, vector<int>(n));
			range(i, 0, n) {
				range(j, 0, m) {
					b[j][i] = a[i][j];
				}
			}
			a = b;
			swap(n, m);
		}

		vector<vector<int>> p(n, vector<int>(m, 1)), q(n, vector<int>(m, 0));
		vector<vector<int>> r(n, vector<int>(m, 1)), s(n, vector<int>(m, 0));
		range(j, 0, m) {
			p[0][j] = a[0][j] % 2;
			r[0][j] = a[0][j] > 1;
		}
		range(i, 0, n) {
			p[i][0] = a[i][0] % 2;
			r[i][0] = a[i][0] > 1;
		}
		range(i, 1, n) {
			range(j, 1, m) {
				p[i][j] = p[i - 1][j - 1] + (a[i][j] % 2);
				r[i][j] = r[i - 1][j - 1] + (a[i][j] > 1);
			}
		}

		range(j, 0, m) {
			q[n - 1][j] = a[n - 1][j] % 2;
			s[n - 1][j] = a[n - 1][j] > 1;
		}
		range(i, 0, n) {
			q[i][0] = a[i][0] % 2;
			s[i][0] = a[i][0] > 1;
		}
		for (int i = n - 2; i >= 0; i--) {
			range(j, 1, m) {
				q[i][j] = q[i + 1][j - 1] + (a[i][j] % 2);
				s[i][j] = s[i + 1][j - 1] + (a[i][j] > 1);
			}
		}

		vector<vector<int>> f(n, vector<int>(m, 0)), g(n, vector<int>(m, 0));
		range(i, 0, n) {
			range(j, 0, m) {
				f[0][0] += max(i, j) * (a[i][j] % 2);
				g[0][0] += max(i, j) * (a[i][j] > 1);
			}
		}

		int x = a[0][0] % 2, y = a[0][0] > 1, k = 0, l = 0;
		range(i, 1ll, n) {
			range(j, 0, i) {
				k += a[i][j] % 2;
				l += a[i][j] > 1;
			}
		}

		range(i, 1, n) {
			f[i][0] = f[i - 1][0] + x - k;
			g[i][0] = g[i - 1][0] + y - l;

			k -= p[n - 1][n - i - 1];
			l -= r[n - 1][n - i - 1];

			x += q[0][i];
			y += s[0][i];
		}

		range(i, 0, n) {
			int x = a[i][0] % 2, y = a[i][0] > 1, k = 0, l = 0;
			range(j, 1, m) {
				int u, v;
				tie(u, v) = end2(i, j, n, m);
				k += q[u][v] - q[i][j];
				tie(u, v) = end1(i, j, n, m);
				k += p[u][v] - p[i][j];
				k += a[i][j] % 2;

				tie(u, v) = end2(i, j, n, m);
				l += s[u][v] - s[i][j];
				tie(u, v) = end1(i, j, n, m);
				l += r[u][v] - r[i][j];
				l += a[i][j] > 1;
			}

			range(j, 1, m) {
				f[i][j] = f[i][j - 1] + x - k;
				g[i][j] = g[i][j - 1] + y - l;

				int u, v;
				if (j < m - 1) {
					tie(u, v) = end2(i, j, n, m);
					k -= q[u][v] - q[i][j];
					tie(u, v) = end1(i, j, n, m);
					k -= p[u][v] - p[i][j];
					k -= a[i][j] % 2;

					tie(u, v) = end2(i, j, n, m);
					l -= s[u][v] - s[i][j];
					tie(u, v) = end1(i, j, n, m);
					l -= r[u][v] - r[i][j];
					l -= a[i][j] > 1;
				}

				x += q[i][j];
				x += p[i][j];
				x -= a[i][j] % 2;

				y += s[i][j];
				y += r[i][j];
				y -= a[i][j] > 1;
			}
		}

		if (flag) {
			swap(n, m);
		}
		range(i, 0, n) {
			range(j, 0, m) {
				if (flag) {
					cout << abs(f[j][i] - g[j][i]) << ' ';
				}
				else {
					cout << abs(f[i][j] - g[i][j]) << ' ';
				}
			}
			cout << endl;
		}
	}
}
