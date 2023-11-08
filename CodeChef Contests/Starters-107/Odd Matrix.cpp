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

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<vector<int>> res(n, vector<int>(n, 0));
		if (n % 2) {
			res[0][0] = 1;
			for (int i = 2; i < n; i += 2) {
				int c = (i - 1) * (i - 1) + 2;
				for (int j = 0; j < i; j += 2) {
					res[j][i - 1] = c;
					res[i - 1][j] = c + 2;
					res[j][i] = c + 4;
					res[i][j] = c + 6;
					c += 8;
				}

				c = (i - 1) * (i - 1) + 1;
				range(j, i - 1, i + 1) {
					range(k, i - 1, i + 1) {
						if (res[j][k] == 0) {
							res[j][k] = c;
							c += 2;
						}
					}
				}
			}
		}
		else {
			range(i, 0, n) {
				range(j, 0, n) {
					res[i][j] = n * i + j + 1;
				}
			}
			for (int j = 0; j < n ; j += 2) {
				swap(res[0][j], res[0][j + 1]);
			}
		}

		range(i, 0, n) {
			arrPrint(res[i]);
		}
	}
}
