<<<<<<< HEAD
#include <bits/stdc++.h>
#define range(it, start, end) for (int it = start; it < end; it++)
#define input(x) cin >> x
#define print(x) cout << x << endl
#define arrPut(var) for (auto &i : var) {cin >> i;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << " ";} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 9;

int dp[(int) 1e6] = {0, 1, 1};

int main() {
	setup();
	range(i, 3, 1e6) {
		dp[i] = (dp[i - 2] + dp[i - 3]) % MOD;
	}
	int tc; input(tc); while (tc--) {
		int n; input(n);
		print(dp[n - 1]);
	}
=======
#include <bits/stdc++.h>
#define range(it, start, end) for (int it = start; it < end; it++)
#define input(x) cin >> x
#define print(x) cout << x << endl
#define arrPut(var) for (auto &i : var) {cin >> i;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << " ";} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 9;

int dp[(int) 1e6] = {0, 1, 1};

int main() {
	setup();
	range(i, 3, 1e6) {
		dp[i] = (dp[i - 2] + dp[i - 3]) % MOD;
	}
	int tc; input(tc); while (tc--) {
		int n; input(n);
		print(dp[n - 1]);
	}
>>>>>>> f6f46ae63ca36b9fa6e961ce3b0edb092483751d
}