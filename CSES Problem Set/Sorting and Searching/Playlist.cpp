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
	int k[n]; arrPut(k);

	map<int, int> ind;

	int dp[n] = {1};
	ind[k[0]] = 0;

	range(i, 1, n) {
		dp[i] = dp[i - 1] + 1;
		if (ind.find(k[i]) != ind.end()) {
			dp[i] = min(dp[i], i - ind[k[i]]);
		}
		ind[k[i]] = i;
	}

	print(*max_element(dp, dp + n));
}