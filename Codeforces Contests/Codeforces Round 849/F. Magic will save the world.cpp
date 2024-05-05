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
	int N = 1e6;
	setup(); int tc; input(tc); while (tc--) {
		int w, f;
		input(w, f);

		int n;
		input(n);

		vector<int> s(n);
		arrPut(s);

		int c = 0;
		for (int i : s) {
			c += i;
		}

		vector<bool> dp(N + 1, false);
		dp[0] = true;
		range(i, 0, n) {
			for (int j = N; j >= s[i]; j--) {
				dp[j] = dp[j] or dp[j - s[i]];
			}
		}

		int res = 1e9;
		range(i, 0, N + 1) {
			if (dp[i]) {
				res = min(res, max((i + w - 1) / w, (c - i + f - 1) / f));
			}
		}

		print(res);
	}
}
