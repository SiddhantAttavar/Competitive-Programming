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
		int n, k;
		input(n, k);

		if (k % 2) {
			print("No");
			continue;
		}

		vector<vector<bool>> res(n, vector<bool>(n, false));
		bool flag = false;
		if (k % 4) {
			if (n % 4 == 0) {
				print("No");
				continue;
			}

			if (k < n) {
				print("No");
				continue;
			}

			range(i, 0, n) {
				res[i][i] = true;
			}
			k -= n;
			flag = true;

			if (k > (n * n) - 2 * n) {
				print("No");
				continue;
			}
		}

		if (k > (n * n)) {
			print("No");
			continue;
		}

		range(i, 0, n / 2) {
			range(j, 0, n / 2) {
				if (flag and (i == j)) {
					continue;
				}
				if (k == 0) {
					break;
				}
				res[2 * i][2 * j] = true;
				res[2 * i][2 * j + 1] = true;
				res[2 * i + 1][2 * j] = true;
				res[2 * i + 1][2 * j + 1] = true;
				k -= 4;
			}
			if (k == 0) {
				break;
			}
		}

		if (k > 0) {
			print("No");
			continue;
		}

		print("Yes");

		range(i, 0, n) {
			arrPrint(res[i]);
		}
	}
}
