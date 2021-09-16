#include <bits/stdc++.h>
#define range(it, start, end) for (int it = start; it < end; it++)
#define input(x) cin >> x
#define print(x) cout << x << endl
#define arrPut(var) for (auto &i : var) {cin >> i;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << " ";} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
	setup();
	
	int n; input(n);

	if (n % 4 != 0 && n % 4 != 3) {
		print(0);
		return 0;
	}

	int x = n * (n + 1) / 4;

	vector<vector<int>> dp(n, vector<int>(x + 1, 0));
	dp[0][0] = 1;

	range(i, 1, n) {
		range(j, 0, x + 1) {
			dp[i][j] = dp[i - 1][j];
			if (j >= i) {
				dp[i][j] = (dp[i][j] + dp[i - 1][j - i]) % MOD;
			}
		}
	}

	print(dp[n - 1][x]);
}