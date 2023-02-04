#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int32_t main() {
	setup();

	int n, m;
	input(n, m);

	vector<int> a(n), b(m);
	arrPut(a);
	arrPut(b);

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	vector<pair<int, int>> v;
	for (int i : a) {
		v.push_back({i, 0});
	}
	for (int i : b) {
		v.push_back({i, 1});
	}
	sort(v.begin(), v.end());

	vector<vector<int>> dp(n + m, vector<int>(n + m));
	range(l, 2, n + m + 1) {
		range(i, 0, n + m) {
			int j = i + l - 1;
			if (j >= n + m) {
				break;
			}

			dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
			if (v[i].second != v[j].second) {
				dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + (v[j].first - v[i].first));
			}
		}
	}

	print(dp[0][n + m - 1]);
}
