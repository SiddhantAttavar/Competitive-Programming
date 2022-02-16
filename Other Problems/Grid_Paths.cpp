#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << (x) << endl;
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

const int MOD = 1e9 + 7;

int main() {
	setup();
	input(int, n);

	bool safe[n][n];
	range(i, 0, n) {
		input(string, s);
		range(j, 0, n) {
			safe[i][j] = s[j] == '.';
		}
	}

	int dp[n][n];
	range(i, 0, n) {
		range(j, 0, n) {
			dp[i][j] = 0;
		}
	}

	dp[0][0] = safe[0][0];
	range(i, 1, n) {
		if (safe[i - 1][0]) {
			dp[i][0] = dp[i - 1][0];
		}
	}
	range(j, 1, n) {
		if (safe[0][j - 1]) {
			dp[0][j] = dp[0][j - 1];
		}
	}
	range(i, 1, n) {
		range(j, 1, n) {
			if (safe[i - 1][j]) {
				dp[i][j] = dp[i - 1][j];
			}
			if (safe[i][j - 1]) {
				dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
			}
		}
	}

	print(dp[n - 1][n - 1] * safe[n - 1][n - 1]);
}
