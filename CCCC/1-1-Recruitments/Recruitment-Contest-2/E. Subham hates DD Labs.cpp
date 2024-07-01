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

bool check(vector<vector<int>> &a, int n, int m) {
	range(i, 0, n - 3) {
		range(j, 0, m - 3) {
			if ((a[i][j] ^ a[i + 1][j] ^ a[i][j + 1] ^ a[i + 1][j + 1]) != (a[i + 2][j + 2] ^ a[i + 3][j + 2] ^ a[i + 2][j + 3] ^ a[i + 3][j + 3])) {
				return false;
			}
			if ((a[i + 2][j] ^ a[i + 3][j] ^ a[i + 2][j + 1] ^ a[i + 3][j + 1]) != (a[i][j + 2] ^ a[i + 1][j + 2] ^ a[i][j + 3] ^ a[i + 1][j + 3])) {
				return false;
			}
		}
	}
	return true;
}

int32_t main() {
	vector<vector<int>> b = {{0, 1}, {2, 3}};
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		int k = 1;
		while (k < max(n, m)) {
			k *= 2;
		}
		k /= 2;

		vector<vector<int>> a(n, vector<int>(m, 0));
		while (k > 0) {
			range(i, 0, n) {
				range(j, 0, m) {
					a[i][j] = 4 * a[i][j] + b[(i / k) % 2][(j / k) % 2];
				}
			}
			k /= 2;
		}

		assert(check(a, n, m));

		print(n * m);
		range(i, 0, n) {
			arrPrint(a[i]);
		}
	}
}
