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
	int q; input(q);

	int dp[n + 1][n + 1];
	fill(dp[0], dp[0] + n, 0);
	range(i, 1, n + 1) {
		dp[i][0] = 0;
		string str; input(str);
		range(j, 1, n + 1) {
			dp[i][j] = str[j - 1] == '*';
		}
	}

	range(i, 1, n + 1) {
		range(j, 1, n + 1) {
			dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}

	while (q--) {
		int x1, y1, x2, y2;
		input(y1);
		input(x1);
		input(y2);
		input(x2);

		x1--;
		y1--;

		print(dp[y2][x2] - dp[y1][x2] - dp[y2][x1] + dp[y1][x1]);
	}
}