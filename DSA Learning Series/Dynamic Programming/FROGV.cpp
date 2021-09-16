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
	int n, k, p;
	input(n);
	input(k);
	input(p);

	pair<int, int> a[n];
	range(i, 0, n) {
		input(a[i].first);
		a[i].second = i;
	}
	sort(a, a + n);

	int dp[n] = {0};
	int curr = 0;
	range(i, 1, n) {
		if (a[i].first - a[i - 1].first > k) {
			curr++;
		}
		dp[a[i].second] = curr;
	}

	range(i, 0, p) {
		int x, y;
		input(x);
		input(y);
		print((dp[x - 1] == dp[y - 1] ? "Yes" : "No"));
	}
}