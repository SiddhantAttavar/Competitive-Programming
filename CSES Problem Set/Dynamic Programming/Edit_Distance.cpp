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
	
	string a, b;
	input(a);
	input(b);

	int n = a.size();
	int m = b.size();

	int dp[n][m];
	dp[0][0] = a[0] != b[0];

	//For j = 0
	range(i, 1, n) {
		dp[i][0] = dp[i - 1][0] + 1;
		if (a[i] == b[0]) {
			dp[i][0] = min(dp[i][0], i);
		}
	}

	//For i = 0
	range(j, 1, m) {
		dp[0][j] = dp[0][j - 1] + 1;
		if (a[0] == b[j]) {
			dp[0][j] = min(dp[0][j], j);
		}
	}

	range(i, 1, n) {
		range(j, 1, m) {
			dp[i][j] = min({
				dp[i - 1][j],
				dp[i][j - 1],
				dp[i - 1][j - 1] - (a[i] == b[j])
			}) + 1;
		}
	}

	print(dp[n - 1][m - 1]);
}