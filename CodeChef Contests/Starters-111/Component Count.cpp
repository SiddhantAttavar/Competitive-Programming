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

void dfs(int i, int j, int k, vector<vector<bool>> &vis) {
	vis[i][j] = true;

	vector<pair<int, int>> next = {
		{i + 1, j},
		{i - 1, j},
		{i, j - 1},
		{i, j + 1},
		{i + 1, j + 1},
		{i + 1, j - 1},
		{i - 1, j + 1},
		{i - 1, j - 1},
	};

	for (pair<int, int> p : next) {
		if (min(p.first, p.second) >= 0 and max(p.first, p.second) < k and !vis[p.first][p.second]) {
			dfs(p.first, p.second, k, vis);
		}
	}
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m, k;
		input(n, m, k);

		int res = 0;
		vector<vector<bool>> v(n, vector<bool>(m, false));
		range(i, 0, 1 << (k * k)) {
			int x = 0;
			int a = 0, b = 0;
			range(j, 0, k * k) {
				if (i & (1 << j)) {
					v[i][j] = false;
					a = max(a, (int) i);
					b = max(b, (int) j);
					x++;
				}
				else {
					v[i][j] = true;
				}
			}

			if (x != k) {
				continue;
			}

			bool flag = false;
			range(l, 0, k) {
				if (!v[l][0]) {
					flag = true;
					break;
				}
			}

			if (!flag) {
				range(l, 1, k) {
					if (!v[0][l]) {
						flag = true;
						break;
					}
				}

				if (!flag) {
					continue;
				}
			}

			flag = false;
			bool l = false;
			range(p, 0, k)  {
				range(q, 0, k) {
					if (!flag and !v[p][q]) {
						dfs(p, q, k, v);
						flag = true;
					}
					else if (!flag and !v[p][q]) {
						l = true;
						break;
					}
				}
				if (l) {
					break;
				}
			}

			if (!l) {
				if (a >= n or b >= m) {
					continue;
				}

				res += (n - a) * (m - b);
			}
		}

		print(res);
	}
}
