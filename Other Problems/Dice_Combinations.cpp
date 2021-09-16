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
	const int MOD = 1e9 + 7;
	input(int, n);
	int dp[max(n + 1, 6)] = {1, 1, 2, 4, 8, 16};
	range(i, 6, n + 1) {
		dp[i] = dp[i - 1];
		range(j, i - 6, i - 1) {
			dp[i] = (dp[i] + dp[j]) % MOD;
		}
	}
	print(dp[n]);
}