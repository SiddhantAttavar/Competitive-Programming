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
	
	int a, b;
	input(a);
	input(b);

	int dp[a + 1][b + 1];

	range(i, 0, a + 1) {
		range(j, 0, b + 1) {
			if (i == j) {
				dp[i][j] = 0;
				continue;
			}

			dp[i][j] = 1e9;

			//Vertical cut
			range(k, 1, j) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
			}

			//Horizontal cuts
			range(k, 1, i) {
				dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
			}
		}
	}

	print(dp[a][b]);
}