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

		if (n % 2 == 0) {
			print(-1);
			continue;
		}

		vector<int> a, b;
		range(i, 0, n * n) {
			if (i % 2 == 0) {
				a.push_back(i + 1);
			}
			else {
				b.push_back(i + 1);
			}
		}

		vector<vector<int>> res(n, vector<int>(n, 1));
		range(i, 0, n) {
			range(j, 0, n) {
				if (i == 0 and j == 0) {
					continue;
				}

				if ((i + j) % 2 == 0) {
					res[i][j] = b.back();
					b.pop_back();
				}
				else {
					res[i][j] = a.back();
					a.pop_back();
				}
			}
		}
		range(i, 0, n) {
			arrPrint(res[i]);
		}
	}
}
