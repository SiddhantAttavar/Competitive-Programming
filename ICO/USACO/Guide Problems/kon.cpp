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

const int N = 1e5 + 1, K = 320;
int v[N];
int dp[N][K];

int32_t main() {
	setup();
	
	int n, q;
	input(n, q);

	while (q--) {
		int a, l, d;
		input(a, l, d);

		if (d >= K) {
			range(i, 0, l) {
				v[a + i * d]++;
			}
		}
		else {
			dp[a][d]++;
			dp[a + d * l][d]--;
		}
	}

	range(j, 1, K) {
		range(i, 1, j + 1) {
			v[i] += dp[i][j];
		}
		range(i, j + 1, n + 1) {
			dp[i][j] += dp[i - j][j];
			v[i] += dp[i][j];
		}
	}

	range(i, 1, n + 1) {
		cout << v[i] << ' ';
	}
}
