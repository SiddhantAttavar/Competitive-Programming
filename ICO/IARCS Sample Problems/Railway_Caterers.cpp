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
	
	input(int, n);
	input(int, k);
	int prefSum[n + 1] = {0};
	range(i, 1, n + 1) {
		cin >> prefSum[i];
		prefSum[i] += prefSum[i - 1];
	}

	int res = INT_MIN;

	int dp[n];
	dp[k - 1] = prefSum[k];
	range(i, k, n) {
		dp[i] = max(dp[i - 1] + prefSum[i + 1] - prefSum[i], prefSum[i + 1] - prefSum[i - k + 1]);
		res = max(res, dp[i]);
	}

	print(res);
}