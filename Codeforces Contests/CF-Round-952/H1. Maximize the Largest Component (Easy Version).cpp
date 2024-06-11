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

int sa, sb, sc, sd, se;

void dfs(int x, int y, int n, int m, vector<vector<bool>> &v) {
	v[x][y] = true;
	vector<pair<int, int>> l = {{x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1}};
	sa = min(sa, x);
	sb = max(sb, x);
	sc = min(sc, y);
	sd = max(sd, y);
	se++;
	if (x > 0 and !v[x - 1][y]) {
		dfs(x - 1, y, n, m, v);
	}
	if (x < n - 1 and !v[x + 1][y]) {
		dfs(x + 1, y, n, m, v);
	}
	if (y > 0 and !v[x][y - 1]) {
		dfs(x, y - 1, n, m, v);
	}
	if (y < m - 1 and !v[x][y + 1]) {
		dfs(x, y + 1, n, m, v);
	}
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<string> a(n);
		arrPut(a);

		vector<vector<bool>> v(n, vector<bool>(m));
		range(i, 0, n) {
			if (a[i].size() != m) {
				return 0;
			}
			range(j, 0, m) {
				v[i][j] = a[i][j] == '.';
			}
		}

		vector<vector<int>> l;
		range(i, 0, n) {
			range(j, 0, m) {
				if (!v[i][j]) {
					sa = n - 1;
					sb = 0;
					sc = m - 1;
					sd = 0;
					se = 0;
					dfs(i, j, n, m, v);
					l.push_back({sa, sb, sc, sd, se});
				}
			}
		}

		vector<int> p(n, 0), q(m, 0);
		range(i, 0, n) {
			range(j, 0, m) {
				p[i] += a[i][j] == '.';
				q[j] += a[i][j] == '.';
			}
		}

		vector<int> r(n + 1, 0), c(m + 1, 0);
		for (vector<int> i : l) {
			r[max(0ll, i[0] - 1)] += i[4];
			r[min(n, i[1] + 2)] -= i[4];
			c[max(0ll, i[2] - 1)] += i[4];
			c[min(m, i[3] + 2)] -= i[4];
		}

		int res = 0, x = 0;
		range(i, 0, n) {
			x += r[i];
			res = max(res, x + p[i]);
		}

		x = 0;
		range(j, 0, m) {
			x += c[j];
			res = max(res, x + q[j]);
		}
		print(res);
	}
}
