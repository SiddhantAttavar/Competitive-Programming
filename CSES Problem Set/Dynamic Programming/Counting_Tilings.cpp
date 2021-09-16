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

ll fact[11] = {1};
ll dp[1001][11];

ll comb(int x, int y) {
	return (fact[x + y] / (fact[x] * fact[y])) % MOD;
}

int main() {
	setup();
	
	int n, m;
	input(n);
	input(m);

	if ((m * n) % 2 == 1) {
		print(0);
		return 0;
	}

	range(i, 1, n + 1) {
		fact[i] = i * fact[i - 1];
	}

	//For i = 0, dp[0][0] = 1, rest all are 0
	dp[0][0] = 1;

	//i represents the width of the rectangle
	range(i, 1, m + 1) {
		//j represents the number of squares cut
		range(j, 0, n) {
			int left = n - j;

			if ((i * n + j) % 2 == 1) {
				continue;
			}

			//Iterate through number of horizontal blocks
			for (int k = left % 2; k <= left; k += 2) {
				//The number of vertical blocks is (left - k) / 2
				int l = (left - k) / 2;

				//The number of combinations of vertical and horizontal blocks
				//is comb(k, l)
				//The number of squares cut from previous level is k
				//So the remaining ways are dp[i - 1][k]
				if (dp[i - 1][k] > 0) {
					dp[i][j] = (dp[i][j] + comb(k, l) * dp[i - 1][k]) % MOD;
				}
			}
		}
		dp[i][n] = dp[i - 1][0];
	}

	range(i, 0, m + 1) {
		range(j, 0, n + 1) {
			cout << dp[i][j] << " ";
		}
		print("");
	}

	//The answer is dp[m][0]
	print(dp[m][0]);
}