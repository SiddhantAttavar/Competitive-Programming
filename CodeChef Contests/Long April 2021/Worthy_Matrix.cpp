#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
	setup();
	int tc; input(tc); while (tc--) {
		ll n, m, k;
		input(n, m, k);

		int grid[n][m];
		range(i, 0, n) {
			arrPut(grid[i]);
		}

		ll prefSum[n + 1][m + 1] = {{0}};
		range(i, 1, n + 1) {
			range(j, 1, m + 1) {
				prefSum[i][j] = prefSum[i - 1][j] + prefSum[i][j - 1] - prefSum[i - 1][j - 1] + grid[i - 1][j - 1];
			}
		}

		ll res = 0;
		range(l, 1, n + 1) {
			range(i, 0, n - l + 1) {
				range(j, 0, m - l + 1) {
					int x = i + l, y = j + l;
					ll sum = prefSum[x][y] - prefSum[x][j] - prefSum[i][y] + prefSum[i][j];
					if (sum >= k * l * l) {
						res++;
					}
				}
			}
		}

		print(res);
	}
}