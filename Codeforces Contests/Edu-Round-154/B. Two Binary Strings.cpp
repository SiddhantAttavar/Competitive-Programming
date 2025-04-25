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
	setup(); int tc; input(tc); while (tc--) {
		string a, b;
		input(a, b);

		int n = a.size();

		vector<int> p1(n + 1, 0), p2(n + 1, 0);
		range(i, 0, n) {
			p1[i + 1] = p1[i] + (a[i] - '0');
			p2[i + 1] = p2[i] + (b[i] - '0');
		}

		vector<int> dp(n + 1, false);
		dp[0] = true;
		range(i, 0, n) {
			range(j, 0, i + 1) {
				dp[i + 1] = dp[i + 1] or (dp[j] and (
					a[i] == a[j] and
					b[i] == b[j] and
					a[i] == b[i]
				));
			}
		}

		print(dp[n] ? "YES" : "NO");
	}
}
