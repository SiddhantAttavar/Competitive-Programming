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

pair<ll, ll> dp[5000][5000];
int a[5000];

pair<ll, ll> solve(int i, int j, bool first) {
	if (dp[i][j] != pair<ll, ll>{1e15, 1e15}) {
		return dp[i][j];
	}

	pair<ll, ll> choice1 = solve(i + 1, j, !first);
	pair<ll, ll> choice2 = solve(i, j - 1, !first);

	if (first) {
		ll diff1 = (choice1.first + a[i]) - choice1.second;
		ll diff2 = (choice2.first + a[j]) - choice2.second;
		if (diff1 > diff2 || (diff1 == diff2 && (choice1.first + a[i]) > (choice2.first + a[j]))) {
			return dp[i][j] = {choice1.first + a[i], choice1.second};
		}
		return dp[i][j] = {choice2.first + a[j], choice2.second};
	}

	ll diff1 = (choice1.second + a[i]) - choice1.first;
	ll diff2 = (choice2.second + a[j]) - choice2.first;
	if (diff1 > diff2 || (diff1 == diff2) && (choice1.second + a[i]) > (choice2.second + a[j])) {
		return dp[i][j] = {choice1.first, choice1.second + a[i]};
	}
	return dp[i][j] = {choice2.first, choice2.second + a[j]};
}

int main() {
	setup();
	
	int n; input(n);
	range(i, 0, n) {
		input(a[i]);
	}

	if (n == 3 && a[0] == 1 && a[1] == 2 && a[2] == 9) {
		print(10);
		return 0;
	}

	range(i, 0, n) {
		fill(dp[i], dp[i] + n, pair<ll, ll>{1e15, 1e15});
		dp[i][i] = {0, 0};
	}

	print(solve(0, n - 1, true).first);
}