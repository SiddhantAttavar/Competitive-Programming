#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int n, k;
vector<pair<pair<int, int>, int>> a;

bool possible(int m) {
	int dp[n] = {a[0].second};
	int maxDP[n] = {a[0].second};
	range(i, 1, n) {
		int prev = a[i].first.second - m;
		int ind = upper_bound(a.begin(), a.end(), pair<pair<int, int>, int>{{prev, LONG_LONG_MAX}, LONG_LONG_MAX}) - a.begin();
		dp[i] = max(dp[i - 1], a[i].second);
		if (ind > 0) {
			dp[i] = max(dp[i], a[i].second + maxDP[ind - 1]);
		}
		maxDP[i] = max(maxDP[i - 1], dp[i]);
	}
	return dp[n - 1] >= k;
}

int32_t main() {
	setup();
	input(n, k);
	a.resize(n);
	range(i, 0, n) {
		input(a[i].first.second, a[i].first.first, a[i].second);
	}
	sort(a.begin(), a.end());

	int sum = 0;
	int maxW = 0;
	for (pair<pair<int, int>, int> p : a) {
		sum += p.second;
		maxW = max(maxW, p.second);
	}
	if (sum < k) {
		print(-1);
		return 0;
	}
	if (maxW >= k) {
		print(1000000000);
		return 0;
	}

	int l = 0, r = 1e9;
	int res = -1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (possible(mid)) {
			res = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	print(res);
}