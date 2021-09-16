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
	
	int n, m;
	input(n);
	input(m);

	vector<int> a(n); arrPut(a);

	vector<vector<int>> dp(n, vector<int>(m + 1, 0));
	
	if (a[0] > 0) {
		//Known value
		dp[0][a[0]] = 1;
	}
	else {
		//Unkown value
		fill(dp[0].begin() + 1, dp[0].end(), 1);
	}

	//For i > 0
	range(i, 1, n) {
		if (a[i] > 0) {
			//Known value
			dp[i][a[i]] = (dp[i - 1][a[i] - 1] + dp[i - 1][a[i]]) % MOD;
			if (a[i] < m) {
				dp[i][a[i]] = (dp[i][a[i]] + dp[i - 1][a[i] + 1]) % MOD;
			}
			continue;
		}

		//Unknown value
		range(j, 1, m + 1) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
			if (j < m) {
				dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
			}
		}
	}

	int sum = 0;
	for (int i : dp[n - 1]) {
		sum = (sum + i) % MOD;
	}
	print(sum);
}