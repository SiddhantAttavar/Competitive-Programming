#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << (x) << endl;
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

int main() {
	setup();

	//Input
	input(int, n);
	input(int, k);
	arrput(int, a, n);
	print("");
	k /= 2;

	int dp[k][n];
	range(l, 0, k) {
		dp[l][0] = 0;
		range(i, 1, n) {
			dp[l][i] = dp[l][i - 1];
			if (l > 0) {
				dp[l][i] = max(dp[l][i], dp[l - 1][i]);
			}
			range(j, 0, i) {
				if (l > 0) {
					dp[l][i] = max(dp[l][i], dp[l - 1][j] + a[i] - a[j]);
				}
				else {
					dp[l][i] = max(dp[l][i], a[i] - a[j]);
				}
			}
		}
	}

	print(dp[k - 1][n - 1]);
}