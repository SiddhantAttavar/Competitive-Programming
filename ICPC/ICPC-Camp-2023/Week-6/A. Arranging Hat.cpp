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

int32_t main() {
	setup();

	int n, m;
	input(n, m);

	vector<vector<char>> a(n);
	range(i, 0, n) {
		string s;
		input(s);
		a[i] = vector<char>(s.begin(), s.end());
		reverse(a[i].begin(), a[i].end());
	}

	int dp[n][n][m][10];
	vector<tuple<int, int, int, int>> p[n][n][m][10];
	range(len, 1, n + 1) {
		range(l, 0, n - len + 1) {
			int r = l + len - 1;
			range(j, 0, m) {
				range(k, 0, 10) {
					dp[l][r][j][k] = 1e9;
					p[l][r][j][k] = {};

					if (k == 0) {
						int x = 0;
						range(i, l, r + 1) {
							x += a[i][j] != '0';
						}
						if (j > 0) {
							dp[l][r][j][k] = dp[l][r][j - 1][9] + x;
							p[l][r][j][k].push_back({l, r, j - 1, 9});
						}
						else {
							dp[l][r][j][k] = x;
						}
						continue;
					}

					dp[l][r][j][k] = dp[l][r][j][k - 1];
					p[l][r][j][k] = {{l, r, j, k - 1}};

					int x = 0;
					for (int s = r - 1; s >= l; s--) {
						x += a[s + 1][j] != '0' + k;
						if (j > 0) {
							int y = dp[l][s][j][k - 1] + dp[s + 1][r][j - 1][9] + x;
							if (y < dp[l][r][j][k]) {
								dp[l][r][j][k] = y;
								p[l][r][j][k] = {{l, s, j, k - 1}, {s + 1, r, j - 1, 9}};
							}
						}
						else {
							int y = dp[l][s][j][k - 1] + x;
							if (y < dp[l][r][j][k]) {
								dp[l][r][j][k] = y;
								p[l][r][j][k] = {{l, s, j, k - 1}};
							}
						}
					}

					x += a[l][j] != '0' + k;
					if (j > 0) {
						int y = dp[l][r][j - 1][9] + x;
						if (y < dp[l][r][j][k]) {
							dp[l][r][j][k] = y;
							p[l][r][j][k] = {{l, r, j - 1, 9}};
						}
					}
					else {
						int y = x;
						// if (l == 0 and r == 2 and j == 0 and k == 1) {
						// 	print(x, dp[l][r][j][k]);
						// }
						if (y < dp[l][r][j][k]) {
							dp[l][r][j][k] = y;
							p[l][r][j][k] = {};
						}
					}
				}
			}
		}
	}

	vector<vector<char>> res(n);
	range(i, 0, n) {
		res[i] = vector<char>(a[i].begin(), a[i].end());
		// arrPrint(res[i]);
	}

	queue<tuple<int, int, int, int>> q;
	q.push({0, n - 1, m - 1, 9});
	while (!q.empty()) {
		int l, r, j, k;
		tie(l, r, j, k) = q.front();
		// print(l, r, j, k);
		q.pop();

		if (p[l][r][j][k].size() == 0) {
			range(x, l, r + 1) {
				res[x][j] = (char) ((int) '0' + k);
			}
			continue;
		}
		// print(l, r, j, k);

		// print(get<1>(p[l][r][j][k][0]));
		range(x, get<1>(p[l][r][j][k][0]) + 1, r + 1) {
			// print(x, j, k);
			res[x][j] = (char) ((int) '0' + k);
		}

		if (get<2>(p[l][r][j][k][0]) == j - 1) {
			range(x, l, r + 1) {
				res[x][j] = (char) ((int) '0' + k);
			}
		}

		for (tuple<int, int, int, int> t : p[l][r][j][k]) {
			q.push(t);
		}
	}

	range(i, 0, n) {
		string t(res[i].begin(), res[i].end());
		reverse(t.begin(), t.end());
		print(t);
	}

	// print(dp[0][n - 1][m - 1][9]);
	// print(get<0>(p[0][2][0][1][0]), get<1>(p[0][2][0][1][0]), get<2>(p[0][2][0][1][0]), get<3>(p[0][2][0][1][0]));
}
