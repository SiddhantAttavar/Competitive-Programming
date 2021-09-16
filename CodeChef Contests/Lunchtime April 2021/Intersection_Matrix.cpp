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
#define int ll

const int MOD = 1e9 + 7;

signed main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m, b;
		input(n, m, b);
		int a[n][m];
		range(i, 0, n) {
			arrPut(a[i]);
		}

		int res = 0;
		range(i, 1, pow(2, n)) {
			range(j, 1, pow(2, m)) {
				int curr = 0;
				range(x, 0, n) {
					range(y, 0, m) {
						if ((i & (1 << x)) > 0 && (j & (1 << y)) > 0) {
							curr += a[x][y];
						}
					}
				}
				res += curr == b;
			}
		}
		print(res % MOD);
	}
}