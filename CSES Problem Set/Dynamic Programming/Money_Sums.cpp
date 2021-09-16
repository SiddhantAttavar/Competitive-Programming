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
	int x[n]; arrPut(x);

	bool dp[n][100001];
	range(i, 0, n) {
		dp[i][0] = true;
		fill(dp[i] + 1, dp[i] + 100001, false);
	}
	dp[0][x[0]] = true;

	range(i, 1, n) {
		range(j, 1, 100001) {
			if (dp[i - 1][j] || (j >= x[i] && dp[i - 1][j - x[i]])) {
				dp[i][j] = true;
			}
		}
	}

	vector<int> res;
	range(j, 1, 100001) {
		range(i, 0, n) {
			if (dp[i][j]) {
				res.push_back(j);
				break;
			}
		}
	}

	print(res.size());
	arrPrint(res);
}