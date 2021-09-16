#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << (x) << endl;
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

long long increaseStrength(long long currStrength) {
	long long finStrength = currStrength;
	int digitSum = 0;
	while (currStrength > 0) {
		digitSum += currStrength % 10;
		currStrength /= 10;
	}
	return finStrength + digitSum * digitSum * digitSum;
}

int main() {
	setup();
	input(int, n);
	
	input(long long, initStrength);
	long long s[n + 1] = {initStrength};
	range(i, 1, n + 1) {
		s[i] = increaseStrength(s[i - 1]);
	}

	/*for (int i : s) {
		cout << i << " ";
	}
	print("");*/

	arrput(int, e, n);
	
	long long dp[n + 1][n + 1];
	range(i, 0, n + 1) {
		range(j, 0, n + 1) {
			dp[i][j] = 0;
		}
	}

	range(i, 0, n + 1) {
		dp[i][i] = 0;
	}
	range(j, 1, n + 1) {
		dp[0][j] = dp[0][j - 1] + s[0] * e[j - 1];
	}
	range(i, 1, n + 1) {
		range(j, i + 1, n + 1) {
			dp[i][j] = max(dp[i - 1][j - 1], dp[i][j - 1] + s[i] * e[j - 1]);
		}
	}

	/*range(i, 0, n + 1) {
		range(j, 0, n + 1) {
			cout << dp[i][j] << " ";
		}
		print("");
	}*/

	long long res = dp[0][n];
	range(i, 1, n + 1) {
		res = max(res, dp[i][n]);
	}
	print(res);
}