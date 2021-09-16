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

	vector<int> h(n), s(n);
	for (int &i : h) {
		cin >> i;
	}
	for (int &i : s) {
		cin >> i;
	}

	vector<vector<int>> dp(x + 1, vector<int>(n + 1, 0));

	//For x > 0
	range(p, 1, x + 1) {
		range(i, 0, n) {
			//If we don't choose the book we get dp[p][i - 1]
			//If we choose the book the remaining money is p - h[i - 1]
			//The maximum pages we can choose with p - h[i - 1] is dp[p - h[i - 1]][i - 1]
			int moneyLeft = p - h[i];

			if (moneyLeft >= 0) {
				dp[p][i + 1] = max(dp[p][i], dp[moneyLeft][i] + s[i]);
			}
			else {
				dp[p][i + 1] = dp[p][i];
			}
		}
	}

	//The answer is dp[x][n]
	print(dp[x][n]);
}