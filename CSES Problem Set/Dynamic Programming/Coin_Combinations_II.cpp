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
	
	int dp[x + 1];

	//For n = 0
	range(i, 0, x + 1) {
		dp[i] = i % c[0] == 0;
	}
	
	range(j, 1, n) {
		range(i, c[j], x + 1) {
			dp[i] = (dp[i] + dp[i - c[j]]) % MOD;
		}
	}

	print(dp[x]);
}