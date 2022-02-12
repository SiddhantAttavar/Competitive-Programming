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

long long v[100001];
int dp[100001][300];

int32_t main() {
	setup();
	
	int n, q;
	input(n, q);

	int k = 300;

	while (q--) {
		int a, l, d;
		input(a, l, d);

		if (d >= k) {
			range(i, 0, l) {
				v[a + (i * d)]++;
			}
		}
		else {
			dp[a][d]++;
			dp[a + (d * l)][d]--;
		}
	}

	range(j, 1, k) {
		range(i, j, n + 1) {
			dp[i][j] += dp[i - j][j];
		}
	}

	range(i, 1, n + 1) {
		range(j, 1, k) {
			v[i] += dp[i][j];
		}
		cout << v[i] << ' ';
	}
}
