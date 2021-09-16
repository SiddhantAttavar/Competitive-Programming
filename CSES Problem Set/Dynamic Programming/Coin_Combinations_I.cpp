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
	
	int n, x;
	input(n);
	input(x);
	int c[n];
	arrPut(c);

	sort(c, c + n);
	int dp[x + 1] = {1};
	fill(dp + 1, dp + x + 1, 0);
	range(i, 1, x + 1) {
		for (int j : c) {
			if (j > i) {
				break;
			}
			dp[i] = (dp[i] + dp[i - j]) % MOD;
		}
	}

	print(dp[x]);
}