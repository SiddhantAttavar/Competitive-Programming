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
	int MOD = (int) 1e9 + 7;
	setup(); int tc; input(tc); while (tc--) {
		int n;
		string s;
		input(n, s);
		sort(s.begin(), s.end());

		int res = 1;
		int x = 1;
		range(i, 1, n) {
			if (s[i] == s[i - 1]) {
				x++;
			}
			else {
				res = (res * (x + 1)) % MOD;
				x = 1;
			}
		}
		res = (res * (x + 1)) % MOD;

		print(res - 1);
	}
}
